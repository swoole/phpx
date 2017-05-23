<?php
$app = new Gtk\Application("test.glade", "window1");

$btn = $app->find("button1");

$btn->on("clicked", function () use ($app) {
    echo "btn1 clicked.\n";
    $app->quit();
});

$app->run();
