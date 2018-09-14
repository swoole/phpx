<?php

namespace phpx\Command;

use Swoole;

use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

class StartWeb extends \Symfony\Component\Console\Command\Command
{
    protected function configure()
    {
        $this
            ->setName('start:web')
            ->setDescription('start php cli-server')
            ->setHelp('This command allows you to run phpx project...');
        $this->addOption('daemon', null, InputOption::VALUE_NONE, 'run as daemon');
        $this->addOption('count', 'c', InputOption::VALUE_OPTIONAL, 'process count', swoole_cpu_num());
        $this->addOption('host', null, InputOption::VALUE_REQUIRED, 'address');
        $this->addOption('port', null, InputOption::VALUE_REQUIRED, 'port');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $count = $input->getOption('count');
        $pool = new Swoole\Process\Pool($count);

        if ($input->getOption('daemon')) {
            swoole\process::daemon();
        }

        $host = $input->getOption('host');
        $port = $input->getOption('port');

        $socket = socket_create(AF_INET, SOCK_STREAM, 0);
        if (!socket_set_option($socket, SOL_SOCKET, SO_REUSEADDR, 1)) {
            $output->write('<error>Unable to set option on socket: ' . socket_strerror(socket_last_error()) . '</error>');
            return;
        }

        if (!socket_set_option($socket, SOL_SOCKET, SO_REUSEPORT, 1)) {
            $output->write('<error> Unable to set option on socket: ' . socket_strerror(socket_last_error()) . '</error>');
            return;
        }

        if (!socket_bind($socket, '127.0.0.1', $port)) {
            $output->write('<error> Unable to bind socket: ' . socket_strerror(socket_last_error()) . '</error>');
            return;
        }
        socket_close($socket);

        $pid_file = getcwd() . '/project.pid';
        if (is_file($pid_file) and \Swoole::$php->os->kill(file_get_contents($pid_file), 0)) {
            $output->writeln('<comment>Server is already running.</comment>');
            return;
        }

        file_put_contents($pid_file, posix_getpid());

        $pool->on("workerStart", function ($pool, $id) use ($host, $port) {
            $process = $pool->getProcess();
            $process->exec("/usr/bin/env", ["php", "-S", "$host:$port"]);
        });

        $pool->start();

        unlink($pid_file);
    }
}