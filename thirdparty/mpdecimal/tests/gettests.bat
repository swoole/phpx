@ECHO OFF

if not exist testdata mkdir testdata
rem copy additional tests
if not exist testdata\baseconv.decTest copy /y testdata_dist\* testdata

if exist testdata\add.decTest goto OUT

rem get official tests
if exist dectest.zip goto UNZIP
powershell -Command "wget http://speleotrove.com/decimal/dectest.zip -outfile dectest.zip"

:UNZIP
powershell -Command "Expand-Archive dectest.zip -DestinationPath testdata"

:OUT
