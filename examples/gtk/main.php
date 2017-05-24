<?php
$app = new Gtk\Application("test.glade", "window1");

$app->setTitle("Power by PHP-X.");
$r = $app->setIcon(__DIR__.'/weixin.jpg');

$app->find("button1")->on("clicked", function () use ($app) {
    $app->quit();
});

$app->find('button3')->on('clicked', function() use ($app) {
    $input = $app->find("entry1");
    $text = $input->getText();
    $app->find('label1')->setText("Value=$text");
});

$app->find('button4')->on('clicked', function() use ($app) {
    $input = $app->find("entry1");
    $input->setText('hello world');
});

$app->run();
