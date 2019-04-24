<?php

namespace phpx;

use Swoole\Upload;
use Symfony\Component\Console\Exception\RuntimeException;

class Builder
{
    private $objects = [];
    private $files = [];

    protected $root;
    protected $cxxflags = '-g';
    protected $cflags = '-g';
    protected $ldflags = '';
    protected $exts = array('.cc', '.cpp', '.c');
    protected $projectName;
    protected $projectType;
    protected $target;
    protected $installTargetDir;
    protected $phpRoot;

    const DIR_SRC = 'src';
    const DIR_INCLUDE = 'include';
    const DIR_LIBRARY = 'lib';
    const DIR_BIN = 'bin';
    const DIR_BUILD = '.build';

    const CXX = 'c++';
    const CC = 'cc';

    const CC_STD = '';
    const CXX_STD = 'c++11';

    const PHPX_LFLAGS = '-lphpx';

    protected $debug;
    protected $verbose;

    protected $configFile;
    protected $config;

    function __construct($debug = false, $verbose = false)
    {
        $this->debug = $debug;
        $this->verbose = $verbose;
        $this->root = getcwd() . '/';
        $this->phpRoot = trim(`php-config --prefix`);

        $this->loadConfig();
        $this->projectName = $this->getConfigValue('project', 'name');
        $this->projectType = $this->getConfigValue('project', 'type');
        $this->cxxflags .= ' ' . $this->getConfigValue('build', 'cxxflags');
        $this->cflags .= ' ' . $this->getConfigValue('build', 'cflags');
        $this->ldflags .= ' ' . $this->getConfigValue('build', 'ldflags');

        if ($this->isExtension()) {
            $php_extension_dir = trim(`php-config --extension-dir`);
            $this->installTargetDir = $php_extension_dir;
            $this->target = $this->root . '/lib/' . $this->projectName . '.so';
        } else {
            $this->installTargetDir = $this->phpRoot . '/bin';
            $this->target = $this->root . '/bin/' . $this->projectName;
        }
    }

    function make()
    {
        if ($this->compile()) {
            $this->link();
        }
    }

    function getTarget()
    {
        return $this->target;
    }

    static function getFileList($dir, $exts, array &$result)
    {
        $files = scandir($dir);
        foreach ($files as $file) {
            if ($file == '.' or $file == '..') {
                continue;
            }
            if (is_dir($dir . '/' . $file)) {
                self::getFileList($dir . '/' . $file, $exts, $result);
            } else {
                if (!in_array('.' . Upload::getFileExt($file), $exts)) {
                    continue;
                }
                $result[] = $dir . '/' . $file;
            }
        }
    }

    function isExtension()
    {
        return $this->projectType == 'ext';
    }

    function isEmbedBinary()
    {
        return $this->projectType == 'bin';
    }

    /**
     * 编译源代码
     * @return bool
     */
    function compile()
    {
        self::getFileList($this->root . self::DIR_SRC, $this->exts, $this->files);

        if (empty($this->files)) {
            throw  new RuntimeException("no src files \n");
        }

        foreach ($this->files as $file) {
            $_file = str_replace($this->root, '', $file);
            $objectFile = $this->root . self::DIR_BUILD . substr($_file, strlen(self::DIR_SRC)) . '.o';
            if (!is_dir(dirname($objectFile))) {
                mkdir(dirname($objectFile), 0777, true);
            }
            $this->objects[] = $objectFile;
            /**
             * 源文件的修改时间晚于目标文件，无需编译
             */
            if (is_file($objectFile) and filemtime($objectFile) >= filemtime($file)) {
                continue;
            }
            /**
             * TODO 头文件依赖分析，头文件修改时需要更新所有 include 它的源文件
             */
            if ($this->debug) {
                $compile_option = '-O0';
            } else {
                $compile_option = '-O2';
            }
            if ($this->isExtension()) {
                $compile_option .= ' -fPIC';
            }
            /**
             * include 路径
             */
            $php_include = trim(`php-config --includes`);
            /**
             * C 源文件
             */
            if (Upload::getFileExt($file) == 'c') {
                $std = $this->getConfigValue('build', 'c_std');
                if ($std) {
                    $compile_option .= '-std=' . $std . ' ';
                }
                $result = $this->exec(self::CC . " $php_include -I./include -c $file -o $objectFile {$compile_option} {$this->cflags}");
            } /**
             * C++ 源代码
             */
            else {
                $std = $this->getConfigValue('build', 'cxx_std');
                if ($std) {
                    $compile_option .= ' -std=' . $std . ' ';
                } else {
                    $compile_option .= ' -std=' . self::CXX_STD . ' ';
                }
                $result = $this->exec(self::CXX . " $php_include -I./include -c $file -o $objectFile {$compile_option} {$this->cxxflags}");
            }
            if ($result === false) {
                return false;
            }
        }
        return true;
    }

    /**
     * 加载配置文件
     */
    protected function loadConfig()
    {
        $this->configFile = $this->root . '/.config.json';
        if (!is_dir($this->root . self::DIR_SRC)) {
            throw  new RuntimeException("no src dir\n");
        }
        if (!is_file($this->configFile)) {
            throw  new RuntimeException("no .config.json[{$this->configFile}]\n");
        }
        $config = json_decode(file_get_contents($this->configFile), true);
        if (empty($config['project']['name'])) {
            throw  new RuntimeException("no project.name option in config.json\n");
        }

        $this->config = $config;
    }

    /**
     * 获取配置名称
     * @param $type
     * @param null $key
     * @return bool
     */
    public function getConfigValue($type, $key = null)
    {
        if (!array_key_exists($type, $this->config)) {
            return false;
        }
        if ($key) {
            return array_key_exists($key, $this->config[$type]) ? $this->config[$type][$key] : false;
        } else {
            return $this->config[$type];
        }
    }

    public function exec($cmd)
    {
        if ($this->verbose) {
            echo $cmd . "\n";
        }
        $handle = popen($cmd, "r");
        $status = pclose($handle);
        if ($status != 0) {
            return false;
        } else {
            return true;
        }
    }

    public function link()
    {
        $objects = implode(' ', $this->objects);
        if (!is_dir(dirname($this->target))) {
            @mkdir(dirname($this->target));
        }

        $link_option = ' -L./lib';
        $libs = trim(`php-config --libs`);
        $ldflags = trim(`php-config --ldflags`);

        /**
         * PHP 的 library 路径
         */
        $link_option .= ' -L' . $this->phpRoot . '/lib';

        if ($this->isExtension()) {
            $link_option .= ' -shared';
            $libs .= " " . self::PHPX_LFLAGS;
            /**
             * MacOS 需要增加连接参数
             */
            if (strcasecmp(PHP_OS, "Darwin") === 0) {
                $link_option .= " -undefined dynamic_lookup";
            }
        } else {
            $libs .= " " . self::PHPX_LFLAGS . ' -lphp7';
        }

        $this->exec(self::CXX . " $objects {$ldflags} {$libs} {$this->ldflags} {$link_option} -o {$this->target}");
    }

    function clean()
    {
        $objects = [];
        self::getFileList($this->root . self::DIR_BUILD, ['.o'], $objects);
        foreach ($objects as $f) {
            unlink($f);
        }
    }

    function install()
    {
        if (!is_file($this->target)) {
            $this->make();
        }
        $this->exec("cp $this->target " .$this->installTargetDir.'/'.basename($this->target));
    }
}
