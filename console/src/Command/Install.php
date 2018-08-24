<?php
namespace phpx\Command;

use phpx\Builder;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;
use Symfony\Component\Console\Input\InputOption;

class Install extends \Symfony\Component\Console\Command\Command
{
    protected function configure()
    {
        $this
            ->setName('install')
            ->setDescription('install phpx project.')
            ->setHelp('Install binary file to system path.');
        $this->addOption('prefix', null,InputOption::VALUE_OPTIONAL, 'prefix of path.', '/usr/local');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $prefix = $input->getOption('prefix');
        $builder = new Builder();
        $builder->install($prefix);
    }
}