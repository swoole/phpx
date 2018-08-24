#!/usr/bin/env php
<?php
/**
 * 打包 phpx 命令行工具
 */
$phar = new Phar('phpx.phar');
$phar->setSignatureAlgorithm(\Phar::SHA1);
$phar->buildFromDirectory(dirname(__DIR__) . '/console', '/\.php$/');
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
file_put_contents($execFile, $new . $sign . substr($bin, 20));
unlink('phpx.phar');
shell_exec('chmod a+x ' . $execFile);