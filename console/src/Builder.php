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
    protected $ldflags = '';
    protected $exts = array('.cc', '.cpp', '.c');
    protected $projectName;
    protected $target;
    protected $installTargetDir;

    const DIR_SRC = 'src';
    const DIR_INCLUDE = 'include';
    const DIR_LIBRARY = 'lib';
    const DIR_BIN = 'bin';
    const DIR_BUILD = '.build';

    const COMPILER = 'c++';

    protected $debug;
    protected $verbose;

    protected $configFile;

    function __construct($debug = false, $verbose = false)
    {
        $this->debug = $debug;
        $this->verbose = $verbose;
        $this->root = getcwd() . '/';
        $this->configFile = $this->root . self::DIR_BUILD . '/config.ini';

        if (!is_dir($this->root . self::DIR_SRC)) {
            throw  new RuntimeException("no src dir\n");
        }
        if (!is_file($this->configFile)) {
            throw  new RuntimeException("no config.ini[{$this->configFile}]\n");
        }
        $config = parse_ini_file($this->configFile, true);
        if (empty($config['project']['name'])) {
            throw  new RuntimeException("no project.name option in config.ini\n");
        }
        $this->projectName = $config['project']['name'];
        $this->cxxflags .= ' ' . $config['build']['cxxflags'];
        $this->ldflags .= ' ' . $config['build']['ldflags'];
        $this->target = $config['build']['target'];
        $this->installTargetDir = $config['install']['target'];
    }

    function make()
    {
        $this->compile();
        $this->link();
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
            //源文件的修改时间晚于目标文件，无需编译
            if (is_file($objectFile) and filemtime($objectFile) >= filemtime($file)) {
                continue;
            }
            if ($this->debug) {
                $compilation_optimization = '-O0';
            } else {
                $compilation_optimization = '-O2';
            }
            $this->exec(self::COMPILER . " {$this->cxxflags} {$compilation_optimization} -fPIC -I./include -c $file -std=c++11 -o " . $objectFile);
        }
    }

    public function exec($cmd)
    {
        if ($this->verbose) {
            echo $cmd."\n";
        }
        shell_exec($cmd);
    }

    public function link()
    {
        $objects = implode(' ', $this->objects);
        if (!is_dir(dirname($this->target))) {
            @mkdir(dirname($this->target));
        }
        $this->exec(self::COMPILER . " $objects {$this->ldflags} -L./lib -o {$this->target}");
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
