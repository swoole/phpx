@ECHO off

set dbg=0
set machine=x64

:getopt
if "%~1"=="/d" (set dbg=1) & shift & goto getopt
if "%~1"=="/m" (set machine=%2) & shift & shift & goto getopt

if "%machine%"=="x64" goto success
if "%machine%"=="ansi64" goto success
echo "valid values for /m are [x64, ansi64]"
exit /b 1
:success

"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere" -latest -property installationPath > vcpath.txt
set /p vcpath=<vcpath.txt
del vcpath.txt
call "%vcpath%\VC\Auxiliary\Build\vcvarsall.bat" x64

if not exist dist64 mkdir dist64
if exist dist64\* del /q dist64\*

cd ..\libmpdec
copy /y Makefile.vc Makefile
nmake clean
nmake MACHINE=%machine% DEBUG=%dbg%

copy /y "libmpdec-4.0.1.lib" ..\vcbuild\dist64
copy /y "libmpdec-4.0.1.dll" ..\vcbuild\dist64
copy /y "libmpdec-4.0.1.dll.lib" ..\vcbuild\dist64
copy /y "libmpdec-4.0.1.dll.exp" ..\vcbuild\dist64
copy /y "mpdecimal.h" ..\vcbuild\dist64


cd ..\libmpdec++
copy /y Makefile.vc Makefile
nmake clean
nmake DEBUG=%dbg%

copy /y "libmpdec++-4.0.1.lib" ..\vcbuild\dist64
copy /y "libmpdec++-4.0.1.dll" ..\vcbuild\dist64
copy /y "libmpdec++-4.0.1.dll.lib" ..\vcbuild\dist64
copy /y "libmpdec++-4.0.1.dll.exp" ..\vcbuild\dist64
copy /y "decimal.hh" ..\vcbuild\dist64

cd ..\vcbuild



