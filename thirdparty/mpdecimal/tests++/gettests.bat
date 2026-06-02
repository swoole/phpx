@ECHO OFF

cd ..\tests
call gettests.bat
cd ..\tests++

if not exist testdata mkdir testdata
if not exist testdata\baseconv.decTest copy /y ..\tests\testdata_dist\* testdata
if not exist testdata\add.decTest copy /y ..\tests\testdata\* testdata
