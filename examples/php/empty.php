<?php
$array = [];
$array["0"] = "string_zero";
$array["1"] = "";

var_dump(empty($array["0"]));
var_dump(empty($array["1"]));
var_dump(empty($array[0]));
