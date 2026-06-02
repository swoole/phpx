@ECHO off

set dbg=0
set machine=ansi32

"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere" -latest -property installationPath > vcpath.txt
set /p vcpath=<vcpath.txt
del vcpath.txt
call "%vcpath%\VC\Auxiliary\Build\vcvarsall.bat" x64_arm

if not exist dist_arm32 mkdir dist_arm32
if exist dist_arm32\* del /q dist_arm32\*

cd ..\libmpdec
copy /y Makefile.vc Makefile
nmake clean
nmake MACHINE=%machine% DEBUG=%dbg%

copy /y "libmpdec-4.0.1.lib" ..\vcbuild\dist_arm32
copy /y "libmpdec-4.0.1.dll" ..\vcbuild\dist_arm32
copy /y "libmpdec-4.0.1.dll.lib" ..\vcbuild\dist_arm32
copy /y "libmpdec-4.0.1.dll.exp" ..\vcbuild\dist_arm32
copy /y "mpdecimal.h" ..\vcbuild\dist_arm32


cd ..\libmpdec++
copy /y Makefile.vc Makefile
nmake clean
nmake DEBUG=%dbg%

copy /y "libmpdec++-4.0.1.lib" ..\vcbuild\dist_arm32
copy /y "libmpdec++-4.0.1.dll" ..\vcbuild\dist_arm32
copy /y "libmpdec++-4.0.1.dll.lib" ..\vcbuild\dist_arm32
copy /y "libmpdec++-4.0.1.dll.exp" ..\vcbuild\dist_arm32
copy /y "decimal.hh" ..\vcbuild\dist_arm32

cd ..\vcbuild

