@ECHO off

"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere" -latest -property installationPath > vcpath.txt
set /p vcpath=<vcpath.txt
del vcpath.txt
call "%vcpath%\VC\Auxiliary\Build\vcvarsall.bat" x64

if not exist dist64 mkdir dist64
if exist dist64\* del /q dist64\*

cd ..\libmpdec
copy /y Makefile.vc Makefile
nmake clean
nmake MACHINE=x64 profile

copy /y "libmpdec-4.0.1.lib" ..\vcbuild\dist64
copy /y "libmpdec-4.0.1.dll" ..\vcbuild\dist64
copy /y "libmpdec-4.0.1.dll.lib" ..\vcbuild\dist64
copy /y "libmpdec-4.0.1.dll.exp" ..\vcbuild\dist64
copy /y "mpdecimal.h" ..\vcbuild\dist64


cd ..\libmpdec++
copy /y Makefile.vc Makefile
nmake clean
nmake

copy /y "libmpdec++-4.0.1.lib" ..\vcbuild\dist64
copy /y "libmpdec++-4.0.1.dll" ..\vcbuild\dist64
copy /y "libmpdec++-4.0.1.dll.lib" ..\vcbuild\dist64
copy /y "libmpdec++-4.0.1.dll.exp" ..\vcbuild\dist64
copy /y "decimal.hh" ..\vcbuild\dist64

cd ..\vcbuild



