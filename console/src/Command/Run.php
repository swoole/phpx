<?php

namespace phpx\Command;

use phpx\Builder;

use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

class Run extends \Symfony\Component\Console\Command\Command
{
    protected function configure()
    {
        $this
            ->setName('run')
            ->setDescription('run phpx project.')
            ->setHelp('This command allows you to run phpx project...');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $builder = new Builder();
        $builder->make();
        $output->write("<info>make success!</info>\nrun\n".str_repeat('=', 80)."\n");
        echo shell_exec('./bin/main');
    }
}