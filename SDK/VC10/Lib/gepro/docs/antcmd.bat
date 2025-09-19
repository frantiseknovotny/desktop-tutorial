@echo off
if "%GEPROENV%"=="" set GEPROENV=c:\_geproenv
if exist %GEPROENV%\env.bat goto ok
echo Je treba nainstalovat Gepro Build Environment !!!
echo Musi byt na C:\_geproenv, nebo nastavte spravnou cestu promenne do GEPROENV !!!
echo http://vyvoj-server.gepro/mediawiki/index.php/Gepro_Build_Environment#Instalace
pause
exit 1

:ok
call %GEPROENV%\env.bat
