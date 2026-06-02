@ECHO off

"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere" -latest -property installationPath > vcpath.txt
set /p vcpath=<vcpath.txt
del vcpath.txt
call "%vcpath%\VC\Auxiliary\Build\vcvarsall.bat" x64

cd ..\libmpdec
if exist Makefile nmake distclean

cd ..\libmpdec++
if exist Makefile nmake distclean

cd ..\tests
if exist Makefile nmake distclean

cd ..\tests++
if exist Makefile nmake distclean

cd ..\vcbuild
if exist additional.decTest del /q additional.decTest
if exist official.decTest del /q official.decTest
if exist dectest.zip del /q dectest.zip
if exist dist64 rd /q /s dist64
if exist dist32 rd /q /s dist32
if exist dist_arm64 rd /q /s dist_arm64
if exist dist_arm32 rd /q /s dist_arm32
if exist testdata rd /q /s testdata

