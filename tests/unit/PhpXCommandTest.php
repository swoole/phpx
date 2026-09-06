<?php

declare(strict_types=1);

use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\TestCase;

final class PhpXCommandTest extends TestCase
{
    private string $temporaryDirectory;

    protected function setUp(): void
    {
        $this->temporaryDirectory = sys_get_temp_dir() . '/phpx-command-' . bin2hex(random_bytes(6));
        mkdir($this->temporaryDirectory, 0777, true);
    }

    protected function tearDown(): void
    {
        $iterator = new RecursiveIteratorIterator(
            new RecursiveDirectoryIterator($this->temporaryDirectory, FilesystemIterator::SKIP_DOTS),
            RecursiveIteratorIterator::CHILD_FIRST,
        );
        foreach ($iterator as $file) {
            $file->isDir() ? rmdir($file->getPathname()) : unlink($file->getPathname());
        }
        rmdir($this->temporaryDirectory);
    }

    public function testInitCreatesCompleteExtensionProject(): void
    {
        $project = $this->temporaryDirectory . '/project';
        $tools = $this->createToolFixtures();
        mkdir($project);
        file_put_contents($project . '/composer.json', "{}\n");
        mkdir($project . '/vendor');

        [$status, $output] = $this->runCommand([
            'init',
            'sample_ext',
            '--target=' . $project,
            '--source-dir=' . $tools,
        ]);

        self::assertSame(0, $status, $output);
        foreach ([
            '.phpx.json',
            'CMakeLists.txt',
            'README.md',
            'build/gen_stub.php',
            'include/sample_ext.h',
            'run-tests.php',
            'src/sample_ext.cc',
            'src/sample_ext.stub.php',
            'tests/sample_ext.phpt',
        ] as $file) {
            self::assertFileExists($project . '/' . $file);
        }
        self::assertFileExists($project . '/composer.json');
        self::assertDirectoryExists($project . '/vendor');
        self::assertSame("gen-stub-fixture\n", file_get_contents($project . '/build/gen_stub.php'));
        self::assertSame("run-tests-fixture\n", file_get_contents($project . '/run-tests.php'));
        $config = json_decode((string) file_get_contents($project . '/.phpx.json'), true);
        self::assertSame(realpath((string) $config['php-config']), $config['php-config']);
        self::assertSame(
            hash('sha256', "gen-stub-fixture\n"),
            $config['managed-files']['build/gen_stub.php'],
        );
    }

    /** @return iterable<string, array{string}> */
    public static function initializedProjectFiles(): iterable
    {
        yield 'CMake configuration' => ['CMakeLists.txt'];
        yield 'stub generator' => ['build/gen_stub.php'];
        yield 'test runner' => ['run-tests.php'];
        yield 'source file' => ['src/existing.cc'];
        yield 'public header' => ['include/existing.h'];
    }

    #[DataProvider('initializedProjectFiles')]
    public function testInitPreservesExistingExtensionProjectContent(string $existingFile): void
    {
        $project = $this->temporaryDirectory . '/project';
        $tools = $this->createToolFixtures();
        mkdir($project);
        $path = $project . '/' . $existingFile;
        if (!is_dir(dirname($path))) {
            mkdir(dirname($path), 0777, true);
        }
        file_put_contents($path, "existing\n");

        [$status, $output] = $this->runCommand([
            'init',
            'sample_ext',
            '--target=' . $project,
            '--source-dir=' . $tools,
        ]);

        self::assertSame(0, $status, $output);
        self::assertSame("existing\n", file_get_contents($path));
        self::assertFileExists($project . '/.phpx.json');
        self::assertFileExists($project . '/build/gen_stub.php');
        self::assertFileExists($project . '/run-tests.php');
        if (!in_array($existingFile, ['CMakeLists.txt', 'run-tests.php'], true)) {
            self::assertFileDoesNotExist($project . '/CMakeLists.txt');
        }
    }

    public function testInstallEnableAndDisable(): void
    {
        $module = $this->temporaryDirectory . '/libsample_ext.so';
        $extensionDirectory = $this->temporaryDirectory . '/extensions';
        $phpIni = $this->temporaryDirectory . '/php.ini';
        mkdir($extensionDirectory);
        file_put_contents($module, 'module-fixture');
        file_put_contents($phpIni, "; base configuration\n");

        [$status, $output] = $this->runCommand([
            'install',
            $module,
            '--extension-dir=' . $extensionDirectory,
        ]);
        self::assertSame(0, $status, $output);
        self::assertSame('module-fixture', file_get_contents($extensionDirectory . '/sample_ext.so'));

        [$status, $output] = $this->runCommand(['enable', 'sample_ext', '--ini=' . $phpIni]);
        self::assertSame(0, $status, $output);
        self::assertStringContainsString("extension=sample_ext\n", file_get_contents($phpIni));

        [$status, $output] = $this->runCommand(['disable', 'sample_ext', '--ini=' . $phpIni]);
        self::assertSame(0, $status, $output);
        self::assertStringContainsString(";extension=sample_ext\n", file_get_contents($phpIni));
    }

    public function testInstallPublishesOnlyHeadersFromIncludeDirectory(): void
    {
        $project = $this->temporaryDirectory . '/project';
        $extensionDirectory = $this->temporaryDirectory . '/extensions';
        $phpIncludeDirectory = $this->temporaryDirectory . '/php/include';
        $module = $project . '/sample_ext.so';
        $runtime = $project . '/build/phpx-runtime/lib/libphpx.so';
        mkdir(dirname($runtime), 0777, true);
        mkdir($extensionDirectory);
        mkdir($project . '/include/nested', 0777, true);
        mkdir($project . '/src');
        file_put_contents($module, 'module-fixture');
        file_put_contents($runtime, 'runtime-fixture');
        file_put_contents($project . '/include/public.h', "public\n");
        file_put_contents($project . '/include/nested/public_detail.h', "public detail\n");
        file_put_contents($project . '/src/private.h', "private\n");
        file_put_contents($project . '/src/sample_ext_arginfo.h', "generated\n");

        $phpConfig = $this->createPhpConfigFixture($phpIncludeDirectory, $extensionDirectory);
        file_put_contents($project . '/.phpx.json', json_encode([
            'name' => 'sample_ext',
            'php-config' => $phpConfig,
        ], JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES) . "\n");

        [$status, $output] = $this->runCommand([
            'install',
            $module,
            '--php-config=' . $phpConfig,
            '--extension-dir=' . $extensionDirectory,
        ], $project);

        self::assertSame(0, $status, $output);
        $installed = $phpIncludeDirectory . '/ext/sample_ext';
        self::assertSame("public\n", file_get_contents($installed . '/public.h'));
        self::assertSame("public detail\n", file_get_contents($installed . '/nested/public_detail.h'));
        self::assertFileDoesNotExist($installed . '/private.h');
        self::assertFileDoesNotExist($installed . '/sample_ext_arginfo.h');
    }

    public function testSwitchRefusesToOverwriteModifiedManagedTools(): void
    {
        $project = $this->temporaryDirectory . '/project';
        $tools = $this->createToolFixtures();
        mkdir($project);
        [$status, $output] = $this->runCommand([
            'init',
            'sample_ext',
            '--target=' . $project,
            '--source-dir=' . $tools,
        ]);
        self::assertSame(0, $status, $output);
        $config = json_decode((string) file_get_contents($project . '/.phpx.json'), true);
        file_put_contents($project . '/run-tests.php', "user-modified\n");

        [$status, $output] = $this->runCommand([
            'switch',
            $config['php-config'],
            '--source-dir=' . $tools,
        ], $project);

        self::assertSame(1, $status);
        self::assertStringContainsString('refusing to overwrite unmanaged or modified file', $output);
        self::assertSame("user-modified\n", file_get_contents($project . '/run-tests.php'));
    }

    private function createToolFixtures(): string
    {
        $directory = $this->temporaryDirectory . '/php-build';
        mkdir($directory);
        file_put_contents($directory . '/gen_stub.php', "gen-stub-fixture\n");
        file_put_contents($directory . '/run-tests.php', "run-tests-fixture\n");
        return $directory;
    }

    private function createPhpConfigFixture(string $includeDirectory, string $extensionDirectory): string
    {
        $path = $this->temporaryDirectory . '/php-config-fixture';
        $script = <<<'PHP'
#!/usr/bin/env php
<?php

$values = json_decode((string) file_get_contents(__DIR__ . '/php-config-values.json'), true);
$option = $argv[1] ?? '';
if (!isset($values[$option])) {
    fwrite(STDERR, "unsupported php-config option: {$option}\n");
    exit(1);
}
echo $values[$option], "\n";
PHP;
        file_put_contents($path, $script . "\n");
        chmod($path, 0755);
        file_put_contents($this->temporaryDirectory . '/php-config-values.json', json_encode([
            '--vernum' => '80500',
            '--include-dir' => $includeDirectory,
            '--extension-dir' => $extensionDirectory,
        ], JSON_THROW_ON_ERROR));
        return $path;
    }

    /** @param list<string> $arguments
     *  @return array{int, string}
     */
    private function runCommand(array $arguments, ?string $workingDirectory = null): array
    {
        $command = [PHP_BINARY, '-n', dirname(__DIR__, 2) . '/bin/phpx', ...$arguments];
        $pipes = [];
        $process = proc_open(
            $command,
            [1 => ['pipe', 'w'], 2 => ['pipe', 'w']],
            $pipes,
            $workingDirectory ?? $this->temporaryDirectory,
        );
        self::assertIsResource($process);
        $output = stream_get_contents($pipes[1]) . stream_get_contents($pipes[2]);
        fclose($pipes[1]);
        fclose($pipes[2]);
        return [proc_close($process), $output];
    }
}
