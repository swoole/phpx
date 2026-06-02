@ECHO off

set dbg=0
set machine=ansi64

"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere" -latest -property installationPath > vcpath.txt
set /p vcpath=<vcpath.txt
del vcpath.txt
call "%vcpath%\VC\Auxiliary\Build\vcvarsall.bat" x64_arm64

if not exist dist_arm64 mkdir dist_arm64
if exist dist_arm64\* del /q dist_arm64\*

cd ..\libmpdec
copy /y Makefile.vc Makefile
nmake clean
nmake MACHINE=%machine% DEBUG=%dbg%

copy /y "libmpdec-4.0.1.lib" ..\vcbuild\dist_arm64
copy /y "libmpdec-4.0.1.dll" ..\vcbuild\dist_arm64
copy /y "libmpdec-4.0.1.dll.lib" ..\vcbuild\dist_arm64
copy /y "libmpdec-4.0.1.dll.exp" ..\vcbuild\dist_arm64
copy /y "mpdecimal.h" ..\vcbuild\dist_arm64


cd ..\libmpdec++
copy /y Makefile.vc Makefile
nmake clean
nmake DEBUG=%dbg%

copy /y "libmpdec++-4.0.1.lib" ..\vcbuild\dist_arm64
copy /y "libmpdec++-4.0.1.dll" ..\vcbuild\dist_arm64
copy /y "libmpdec++-4.0.1.dll.lib" ..\vcbuild\dist_arm64
copy /y "libmpdec++-4.0.1.dll.exp" ..\vcbuild\dist_arm64
copy /y "decimal.hh" ..\vcbuild\dist_arm64

cd ..\vcbuild
