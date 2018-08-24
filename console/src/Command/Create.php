<?php
namespace phpx\Command;

use phpx\Builder;

use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

class Create extends \Symfony\Component\Console\Command\Command
{
    protected function configure()
    {
        $this
            ->setName('create')
            ->setDescription('create a phpx project.')
            ->setHelp('This command allows you to create a phpx project...');
        $this->addArgument('project_name', InputArgument::REQUIRED, 'project_name');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $project_name = $input->getArgument('project_name');
        mkdir($project_name);
        mkdir($project_name.'/'.Builder::DIR_BIN);
        mkdir($project_name.'/'.Builder::DIR_SRC);
        mkdir($project_name.'/'.Builder::DIR_INCLUDE);
        mkdir($project_name.'/'.Builder::DIR_LIBRARY);
        mkdir($project_name.'/'.Builder::DIR_BUILD);
        $iniConfig = <<<HTML
[project]
name = "{$project_name}"
version = "0.0.1"
authors = ""
deps = ""

[build]
link = ""
HTML;
        file_put_contents($project_name.'/config.ini', $iniConfig);
    }
}