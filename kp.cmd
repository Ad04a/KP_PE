@echo off
setlocal

if exist kp_settings.txt (
    for /f "tokens=1,2 delims==" %%A in (kp_settings.txt) do (
        set %%A=%%B
    )
) else (
    echo Settings not found. Run: kp prepare
    exit /b 1
)

rem === Route commands ===

if "%1"=="" goto do_execute
if "%1"=="build" goto do_make
if "%1"=="clean" goto do_clean
if "%1"=="cleanbuild" goto do_cleanbuild
if "%1"=="prepare" goto do_prepare

if "%1"=="run" goto do_run

echo Unknown command: %1
echo.
echo Available commands:
echo   kp
echo   kp build
echo   kp clean
echo   kp cleanbuild
echo   kp run
exit /b


:do_make
%BASH% --noprofile --norc -lc "make build"
exit /b

:do_clean
%BASH% --noprofile --norc -lc "make clean"
exit /b

:do_cleanbuild
%BASH% --noprofile --norc -lc "make clean"
%BASH% --noprofile --norc -lc "make build"
exit /b

:do_run
if exist "%EXE%" (
    "%EXE%"
) else (
    echo Executable not found: %EXE%
    echo Try: kp build
)
exit /b

:do_execute
del /f /q "%EXE%"
%BASH% --noprofile --norc -lc "make build"
goto do_run

:do_prepare
if exist kp_settings.txt (
    echo "Settings file (kp_settings.txt) already exists!"
) else (
    echo "BASH=enter the path to your GitBash"> kp_settings.txt
    echo "EXE=Build\KP_PE.exe" >> kp_settings.txt
)

