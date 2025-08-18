<?php

namespace Phpx\Command;

use League\CLImate\CLImate;
use Symfony\Component\Console\Helper\DescriptorHelper;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

class EnableCommand extends BaseCommand
{
    protected function configure(): void
    {
        $this->ignoreValidationErrors();
        $this->setName('enable')
            ->setDescription('Enable the phpx extension');
    }

    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $info = $this->getPhpConfigInfo($input);
        $this->modifyExtensionInPhpIni($info['ini-path'] . '/php.ini', true);
        $output->writeln("<info>Enable phpx extension `{$this->extName}` successful</info>");
        return 0;
    }
}
