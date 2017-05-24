<?php
$app = new Gtk\Application("test.glade", "window1");

$app->find("button1")->on("clicked", function () use ($app) {
    $app->quit();
});

$app->find('button3')->on('clicked', function() use ($app) {
    $input = $app->find("entry1");
    $text = $input->getText();
    echo "btn3 clicked. text=$text\n";
});

$app->find('button4')->on('clicked', function() use ($app) {
    $input = $app->find("entry1");
    $input->setText('hello world');
});

$app->run();
