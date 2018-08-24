<?php
namespace phpx\Command;

use phpx\Builder;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

class Build extends \Symfony\Component\Console\Command\Command
{
    protected function configure()
    {
        $this
            ->setName('build')
            ->setDescription('build phpx project.')
            ->setHelp('This command allows you to build phpx project...');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $builder = new Builder();
        $builder->make();
    }
}