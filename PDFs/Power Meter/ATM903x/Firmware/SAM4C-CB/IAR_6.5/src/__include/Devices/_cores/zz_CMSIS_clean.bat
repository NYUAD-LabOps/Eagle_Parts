echo OFF
cls
set choice=
set /P choice=This script will remove all files except cores relative includes. Proceed ? Y/N
if '%choice%'=='y' goto erase
if '%choice%'=='Y' goto erase
goto noerase

:erase
echo Erasing files...
rmdir Device /Q /S
rmdir CMSIS\Documentation /Q /S
rmdir CMSIS\DSP_Lib /Q /S
rmdir CMSIS\Lib /Q /S
del CMSIS\*.pdf /Q /F
del CMSIS\*.htm /Q /F
del CMSIS\*.txt /Q /F
echo ...done
goto end

:noerase
echo Command aborted.
goto end



:end