<?php

namespace Phpx\Command;

use League\CLImate\CLImate;
use Symfony\Component\Console\Helper\DescriptorHelper;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

class DisableCommand extends BaseCommand
{
    protected function configure(): void
    {
        $this->ignoreValidationErrors();
        $this->setName('disable')
            ->setDescription('Disable the phpx extension');
    }

    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $info = $this->getPhpConfigInfo($input);
        $this->modifyExtensionInPhpIni($info['ini-path'] . '/php.ini', false);
        $output->writeln("<info>Disable phpx extension `{$this->extName}` successful</info>");
        return 0;
    }
}
