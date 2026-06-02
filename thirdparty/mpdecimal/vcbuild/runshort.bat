@ECHO OFF

rem Release or debug build.
set DBG=0
if "%1%" == "/d" set DBG=1

rem Build libmpdec tests.
cd ..\tests
copy /y Makefile.vc Makefile
nmake clean
nmake DEBUG=%DBG%

rem # Download the official test cases (text files).
call gettests.bat

echo.
echo # ========================================================================
echo #                         libmpdec: static library
echo # ========================================================================
echo.

echo.
<nul (set /p x="Running official tests ... ")
echo.
echo.
runtest.exe official.decTest
if %errorlevel% neq 0 goto out

echo.
<nul (set /p x="Running additional tests ... ")
echo.
echo.
runtest.exe additional.decTest
if %errorlevel% neq 0 goto out

echo.
echo # ========================================================================
echo #                         libmpdec: shared library
echo # ========================================================================
echo.

echo.
<nul (set /p x="Running official tests ... ")
echo.
echo.
runtest_shared.exe official.decTest
if %errorlevel% neq 0 goto out

echo.
<nul (set /p x="Running additional tests ... ")
echo.
echo.
runtest_shared.exe additional.decTest
if %errorlevel% neq 0 goto out


rem Build libmpdec++ tests.
cd ..\tests++
copy /y Makefile.vc Makefile
nmake clean
nmake DEBUG=%DBG%

rem # Copy or download the official test cases (text files).
call gettests.bat

echo.
echo # ========================================================================
echo #                        libmpdec++: static library
echo # ========================================================================
echo.

echo.
<nul (set /p x="Running official tests ... ")
echo.
echo.
runtest.exe official.topTest --thread
if %errorlevel% neq 0 goto out

echo.
<nul (set /p x="Running additional tests ... ")
echo.
echo.
runtest.exe additional.topTest --thread
if %errorlevel% neq 0 goto out

echo.
<nul (set /p x="Running API tests (single thread) ... ")
echo.
echo.
apitest.exe
if %errorlevel% neq 0 goto out

echo.
<nul (set /p x="Running API tests (threaded) ... ")
echo.
echo.
apitest.exe --thread
if %errorlevel% neq 0 goto out

echo.
echo # ========================================================================
echo #                        libmpdec++: shared library
echo # ========================================================================
echo.

echo.
<nul (set /p x="Running official tests ... ")
echo.
echo.
runtest_shared.exe official.topTest --thread
if %errorlevel% neq 0 goto out

echo.
<nul (set /p x="Running additional tests ... ")
echo.
echo.
runtest_shared.exe additional.topTest --thread
if %errorlevel% neq 0 goto out

echo.
<nul (set /p x="Running API tests (single thread) ... ")
echo.
echo.
apitest_shared.exe
if %errorlevel% neq 0 goto out

echo.
<nul (set /p x="Running API tests (threaded) ... ")
echo.
echo.
apitest_shared.exe --thread
if %errorlevel% neq 0 goto out


:out
set exitcode=%errorlevel%
cd ..\vcbuild
exit /b %exitcode%
