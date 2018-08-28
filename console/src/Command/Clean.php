<?php

namespace phpx\Command;

use phpx\Builder;

use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

class Clean extends \Symfony\Component\Console\Command\Command
{
    protected function configure()
    {
        $this
            ->setName('clean')
            ->setDescription('Clean object files')
            ->setHelp('This command allows you to clean object files...');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $builder = new Builder();
        $builder->clean();
    }
}