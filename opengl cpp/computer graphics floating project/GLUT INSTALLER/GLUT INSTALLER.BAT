@ECHO OFF
COLOR 1A
ECHO.
ECHO                 ------------------------------------------------
ECHO                 ^|     OPENGL CODEBLOCKS GLUT INSTALLER V0.1    ^|
ECHO                 ^|                                              ^|
ECHO                 ^|           MD.Kamruzzaman Tanvir              ^|
ECHO                 ------------------------------------------------
ECHO                 ^|--^> GITHUB: https://github.com/kztanvir/      ^|
ECHO                 ------------------------------------------------
ECHO.
REM LET THE GAME BEGIN...
REM TESTED ONLY IN WINDOWS 8.1 64 BIT SYSTEM
ECHO.
REM SETTING THE DRIVE LETTER
SET "Drive=C"
SET "CURRENTDIR=%~DP0"
ECHO.
ECHO PLEASE MAKE SURE 
ECHO.
ECHO --^> YOU INSTALLED "CODEBLOCKS MINGW V20.03"
ECHO.
ECHO --^> THIS SCRIPT HAS GRANTED "RUN AS ADMINISTRATOR" PRIVILEGES
ECHO.
ECHO --^> YOU HAVE 64BIT WINDOWS OS
ECHO.
PAUSE
TIMEOUT /T 2 >null
SET "MINGW=%Drive%:\Program Files\CodeBlocks\MinGW"
SET "CBSHARE=%Drive%:\Program Files\CodeBlocks\share\CodeBlocks"
ECHO.
ECHO SETING THE DIR TO MOVE THE FILES FOR CODEBLOCKS
TIMEOUT /T 2 >null
SET "binary=%Drive%:\Windows\"
SET "library=%MINGW%\lib\"
SET "includeGL=%MINGW%\include\GL\"
SET "RglutCbp=%CBSHARE%\templates\"
SET "RwizScr=%CBSHARE%\templates\wizard\glut\"
ECHO.
ECHO SETTING THE LOCAL FILES
TIMEOUT /T 2 >null
SET "Cbin=%CURRENTDIR%bin"
SET "Clib=%CURRENTDIR%lib"
SET "Cinc=%CURRENTDIR%include\GL"
SET "Cdtc=%CURRENTDIR%dtc"
ECHO.
ECHO CREATE THE FOLDER GL
TIMEOUT /T 2 >null
ECHO.
MKDIR "%includeGL%"
ECHO.
ECHO COPYING THE LOCAL FILES TO THE TARGETED DIRECTORY
ECHO.
TIMEOUT /T 2 >null
XCOPY "%Cdtc%\glut.cbp" "%RglutCbp%" /F /Y /I
TIMEOUT /T 2 >null
XCOPY "%Cdtc%\wizard.script" "%RwizScr%" /F /Y /I
TIMEOUT /T 2 >null
XCOPY "%Cbin%\freeglut.dll" "%binary%" /F /Y /I
TIMEOUT /T 2 >null
XCOPY "%Clib%" "%library%" /F /Y /I
TIMEOUT /T 2 >null
XCOPY "%Cinc%" "%includeGL%" /F /Y /I
TIMEOUT /T 2 >null
ECHO.
ECHO DONE.....
ECHO.
ECHO PLEASE CHECK YOURE CODEBOCKS TO MAKE SURE IT WORKS NOW.
PAUSE
