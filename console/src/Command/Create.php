<?php

namespace phpx\Command;

use phpx\Builder;

use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

class Create extends \Symfony\Component\Console\Command\Command
{
    protected function configure()
    {
        $this
            ->setName('create')
            ->setDescription('Create a phpx project')
            ->setHelp('This command allows you to create a phpx project...');
        $this->addArgument('project_name', InputArgument::REQUIRED, 'project_name');
        $this->addOption('bin', null, InputOption::VALUE_NONE, 'create a binary project');
        $this->addOption('ext', null, InputOption::VALUE_NONE, 'create an extension project');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $root = getcwd() . '/';;
        $project_name = $input->getArgument('project_name');
        $bin = $input->getOption('bin');
        $path = $root . $project_name;
        if (is_dir($root . $project_name)) {
            $output->write("<error>Failed to create project\nThe project dir[$path] is exists.</error>\n");
            return;
        }

        mkdir($path);
        mkdir($path . '/' . Builder::DIR_BIN);
        mkdir($path . '/' . Builder::DIR_SRC);
        mkdir($path . '/' . Builder::DIR_INCLUDE);
        mkdir($path . '/' . Builder::DIR_LIBRARY);
        mkdir($path . '/' . Builder::DIR_BUILD);

        $php_include = trim(`php-config --includes`);
        $php_libs = trim(`php-config --libs`);
        $php_ldflags = trim(`php-config --ldflags`);
        $php_extension_dir = trim(`php-config --extension-dir`);

        if ($bin) {
            $ini = <<<CODE
[project]
name = "{$project_name}"

[build]
target="bin/{$project_name}"
ldflags = "{$php_ldflags} {$php_libs} -lphp7 -lphpx"
cxxflags = "{$php_include}"
CODE;
            file_put_contents($path . '/config.ini', $ini);

            $src = <<<HTML
#include "phpx_embed.h"
#include <iostream>

using namespace php;
using namespace std;

int main(int argc, char * argv[])
{
    VM vm(argc, argv);
    cout << "hello world" << endl;
    echo("hello world\\n");
    return 0;
}
HTML;
            file_put_contents($path . '/src/main.cpp', $src);
        } else {
            $ini = <<<HTML
[project]
name = "{$project_name}"

[build]
target="lib/{$project_name}.so"
ldflags = "-shared {$php_ldflags} {$php_libs} -lphpx"
cxxflags = "-fPIC {$php_include}"

[install]
target="$php_extension_dir"
HTML;
            file_put_contents($path . '/config.ini', $ini);

            $date = date('Y-m-d');
            $src = <<<HTML
#include "phpx.h"
#include <iostream>

using namespace php;
using namespace std;

PHPX_FUNCTION({$project_name}_hello)
{
    echo("argc=%d\\n", args.count());
    retval = "hello world\\n";
}

PHPX_EXTENSION()
{
    Extension *extension = new Extension("{$project_name}", "0.0.1");

    extension->onStart = [extension]() noexcept {
        extension->registerConstant("QUEUE_VERSION", 1001);
    };

    //extension->onShutdown = [extension]() noexcept {
    //};

    //extension->onBeforeRequest = [extension]() noexcept {
    //    cout << extension->name << "beforeRequest" << endl;
    //};

    //extension->onAfterRequest = [extension]() noexcept {
    //    cout << extension->name << "afterRequest" << endl;
    //};

    extension->info({"{$project_name} support", "enabled"},
                    {
                        {"version", extension->version},
                        {"date", "$date"},
                    });
    extension->registerFunction(PHPX_FN({$project_name}_hello));

    return extension;
}
HTML;
            file_put_contents($path . '/src/main.cpp', $src);
        }
    }
}