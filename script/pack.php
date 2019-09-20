#!/usr/bin/env php
<?php
echo "start build phpx tool...\r\n";
/**
 * -d phar.readonly=off
 */
if (ini_get('phar.readonly') == '1') {
    echo "\033[31mNeed to set phar.readonly=Off..\033[0m\r\n";
    exit;
}
if(!extension_loaded('zlib')) {
    echo "\033[31mzlib extension not found..\033[0m\r\n";
    exit;
}

/**
 * 打包 phpx 命令行工具
 */
$phar = new Phar('phpx.phar');
$phar->setSignatureAlgorithm(\Phar::SHA1);
$phar->buildFromDirectory(dirname(__DIR__) . '/console', '/\.php$/');
$phar->compressFiles(Phar::GZ);
$phar->stopBuffering();
$phar->setStub($phar->createDefaultStub('console.php'));
/**
 * SHA1签名
 */
$content = file_get_contents('phpx.phar');
$bin = substr($content, -28, 28);
$new = '#!/usr/bin/env php' . "\n" . substr($content, 0, strlen($content) - 28);
$sign = sha1($new, true);
/**
 * 打包
 */
$execFile = dirname(__DIR__) . '/bin/phpx';
if (!is_dir(dirname($execFile))) {
    mkdir(dirname($execFile));
}
file_put_contents($execFile, $new . $sign . substr($bin, 20));
unlink('phpx.phar');
shell_exec('chmod a+x ' . $execFile);
echo "phpx tool build success.\n";
