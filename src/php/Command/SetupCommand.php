<?php

namespace Phpx\Command;

use League\CLImate\CLImate;
use Symfony\Component\Console\Helper\DescriptorHelper;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

class SetupCommand extends BaseCommand
{
    protected function configure(): void
    {
        $this->ignoreValidationErrors();
        $this->setName('setup')
            ->setDescription('Setup the phpx extension');
    }

    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $info = $this->getPhpConfigInfo($input);
        $libFile = $this->cwd . '/lib/libext.so';
        if (!is_file($libFile)) {
            $this->make();
        }
        copy($libFile, $info['extension-dir'] . '/' . $this->extName . '.so');
        $output->writeln("<info>The phpx extension `{$this->extName}` installation successful</info>");
        return 0;
    }
}
