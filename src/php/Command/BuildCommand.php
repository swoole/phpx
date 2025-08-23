<?php

namespace Phpx\Command;

use League\CLImate\CLImate;
use Symfony\Component\Console\Helper\DescriptorHelper;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

class BuildCommand extends BaseCommand
{
    protected function configure(): void
    {
        $this->ignoreValidationErrors();
        $this->setName('build')->setDescription('Build the phpx extension');
    }

    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $info = $this->getPhpConfigInfo($input);
        $libphpx = $info['prefix'] . '/lib/libphpx.so';

        // build libphpx.so if it does not exist
        if (!file_exists($libphpx)) {
            $output->writeln("<comment>Building phpx library</comment>");
            system('cd vendor/swoole/phpx && cmake . -D php_dir=' . $info['prefix'] . ' && make -j ' . $this->nproc . ' phpx && cd -');
            $tmpLibphpx = 'vendor/swoole/phpx/lib/libphpx.so';
            if (!is_file($tmpLibphpx)) {
                throw  new \RuntimeException("libphpx.so not found, please run 'cmake .' in the PHPX root directory.");
            }
            system("cp $tmpLibphpx {$info['prefix']}/lib");
            system('cp -r vendor/swoole/phpx/include ' . $info['prefix'] . '/include/phpx');
            $output->writeln("<info>Library phpx installation successful</info>");
        }

        $output->writeln("<comment>Generating function argument information stubs</comment>");
        system('php vendor/swoole/phpx/bin/gen_stub.php ' . $this->cwd . '/src');

        $output->writeln("<comment>Building extension</comment>");
        $this->make();

        return 0;
    }
}
