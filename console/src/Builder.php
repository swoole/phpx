<?php
namespace phpx;

use Symfony\Component\Console\Exception\RuntimeException;

class Builder
{
    private $objects;
    private $files;

    protected $cxxflags = '-g';
    protected $exts = array('.cc', '.cpp', '.c');
    protected $projectName;

    const DIR_SRC = 'src';
    const DIR_INCLUDE = 'include';
    const DIR_LIBRARY = 'lib';
    const DIR_BIN = 'bin';
    const DIR_BUILD = '.build';

    function __construct()
    {
        if (!is_dir(self::DIR_SRC)) {
            throw  new RuntimeException("no src dir\n");
        }
        if (!is_file('config.ini')) {
            throw  new RuntimeException("no config.ini\n");
        }
        $config = parse_ini_file('config.ini', true);
        if (empty($config['project']['name'])) {
            throw  new RuntimeException("no project.name option in config.ini\n");
        }
        $this->projectName = $config['project']['name'];
    }

    function make()
    {
        $this->compile();
        $this->link();
    }

    function getFileList($dir = 'src')
    {
        $files = scandir($dir);
        foreach ($files as $file) {
            if ($file == '.' or $file == '..') {
                continue;
            }
            if (is_dir($dir . '/' . $file)) {
                $this->getFileList($dir . '/' . $file);
            } else {
                //扩展名必须为规定的
                if (!in_array(strstr($file, '.'), $this->exts)) {
                    continue;
                }
                $this->files[] = $dir . '/' . $file;
            }
        }
    }

    function compile()
    {
        $this->getFileList();

        if (empty($this->files)) {
            throw  new RuntimeException("no src files \n");
        }

        foreach ($this->files as $file) {
            $objectFile = self::DIR_BUILD . substr($file, strlen(self::DIR_SRC)) . '.o';
            if (!is_dir(dirname($objectFile))) {
                mkdir(dirname($objectFile), 0777, true);
            }
            $this->objects[] = $objectFile;
            //源文件的修改时间晚于目标文件，无需编译
            if (is_file($objectFile) and filemtime($objectFile) >= filemtime($file)) {
                continue;
            }
            $cmd = "c++ {$this->cxxflags} -I./include -c $file -std=c++11 -fPIC -o " . $objectFile;
            echo $cmd . "\n";
            $output = shell_exec($cmd);
        }
    }

    public function link()
    {
        $objects = implode(' ', $this->objects);
        $cmd = "c++ $objects -L./lib -o " . self::DIR_BIN . "/{$this->projectName}";
        echo $cmd . "\n";;
        $output = shell_exec($cmd);
    }

    function install($prefix = '/usr/local')
    {
        $binFile = self::DIR_BIN . '/' . $this->projectName;
        if (!is_file($binFile)) {
            $this->make();
        }
        shell_exec("cp $binFile ".$prefix . '/bin/' . $this->projectName);
    }
}
