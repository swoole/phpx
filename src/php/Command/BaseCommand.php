<?php

namespace Phpx\Command;

use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;

abstract class BaseCommand extends Command
{
    protected string $cwd;
    protected string $extName;
    protected int $nproc;

    protected function parsePhpConfigOutput(string $output, bool $alwaysArray = false): array
    {
        $result = [];
        $lines = preg_split("/\r\n|\n|\r/", $output);

        foreach ($lines as $line) {
            $line = trim($line);
            if ($line === '' || stripos($line, 'Options:') === 0) {
                continue;
            }

            if (!preg_match('/^--([^\s]+)\s+(?:\[(.*)\]|(.*))$/', $line, $m)) {
                continue;
            }

            $name = $m[1];
            $rawValue = isset($m[2]) && $m[2] !== '' ? $m[2] : ($m[3] ?? '');
            $rawValue = trim($rawValue);

            if ($rawValue === '') {
                $value = [];
            } else {
                $parts = preg_split('/\s+/', $rawValue);
                if ($alwaysArray) {
                    $value = $parts;
                } else {
                    $value = count($parts) === 1 ? $parts[0] : $parts;
                }
            }

            $result[$name] = $value;
        }

        return $result;
    }

    protected function getExtName()
    {
        $dir = $this->cwd . '/src';

        $files = scandir($dir);
        foreach ($files as $file) {
            if ($file === '.' || $file === '..') {
                continue;
            }
            $path = $dir . '/' . $file;
            $content = file_get_contents($path);
            if (preg_match('/#define EXT_NAME "([a-z0-9_]+)"/i', $content, $m)) {
                return $m[1];
            }
        }
    }

    protected function make()
    {
        shell_exec('cmake .');
        shell_exec('make -j' );
    }

    protected function getPhpConfigInfo(InputInterface $input)
    {
        $php_dir = $input->getOption('php-dir');
        if ($php_dir) {
            $php_config = realpath($php_dir) . '/bin/php-config';
        } else {
            $php_config = 'php-config';
        }


        $output = shell_exec($php_config);
        return $this->parsePhpConfigOutput($output);
    }

    protected function modifyExtensionInPhpIni($phpIniPath, $enable)
    {
        $extension = $this->extName;
        if (!file_exists($phpIniPath)) {
            if (!$enable) {
                return true; // If disabling and file doesn't exist, nothing to do
            }
            if (!file_put_contents($phpIniPath, "extension=$extension\n")) {
                throw new \RuntimeException("PHP ini file does not exist or is not writable: $phpIniPath");
            }
            return true;
        }

        $iniContent = file($phpIniPath, FILE_IGNORE_NEW_LINES);
        if ($iniContent === false and $enable) {
            throw new \RuntimeException("Failed to read PHP ini file: $phpIniPath");
        }

        $extensionPattern = '/^(\s*)(;)?\s*extension\s*=\s*' . preg_quote($extension) . '(\.so)?\s*$/i';
        $extensionFound = false;
        $modified = false;

        foreach ($iniContent as $lineNum => $line) {
            if (preg_match($extensionPattern, $line, $matches)) {
                $extensionFound = true;
                $leadingWhitespace = $matches[1];
                $currentlyEnabled = empty($matches[2]);

                if ($currentlyEnabled !== $enable) {
                    $newLine = $leadingWhitespace;
                    if (!$enable) {
                        $newLine .= ';';
                    }
                    $newLine .= 'extension=' . $extension;

                    $iniContent[$lineNum] = $newLine;
                    $modified = true;
                }
            }
        }

        if (!$extensionFound) {
            $newLine = $enable ? 'extension=' . $extension : ';extension=' . $extension;
            $iniContent[] = $newLine;
            $iniContent[] = "\n";
            $modified = true;
        }

        if ($modified) {
            return file_put_contents($phpIniPath, implode(PHP_EOL, $iniContent)) !== false;
        }

        return true;
    }

    public function __construct()
    {
        parent::__construct();

        $this->cwd = getcwd();
        $this->nproc = shell_exec('nproc');

        $this->extName = $this->getExtName();
        if (empty($this->extName)) {
            throw new \RuntimeException("Failed to get extension name from source files.");
        }

        $this->addOption("php-dir", null, InputOption::VALUE_REQUIRED, "Set the root path of PHP");
    }
}
