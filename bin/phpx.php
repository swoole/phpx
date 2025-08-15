<?php
require dirname(__DIR__) . '/vendor/autoload.php';

use Symfony\Component\Console\Application;
use Phpx\Command\BuildCommand;

$application = new Application();
$application->add(new BuildCommand());
$application->run();
