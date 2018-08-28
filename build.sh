cd console
echo "composer update"
composer update
cd ../
/usr/bin/env php -c console/php.ini script/pack.php
