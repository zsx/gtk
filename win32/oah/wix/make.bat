@echo off
set API_VER=2.0
set RELEASE_PATH=%~dp0\..\Win32\Release
%OAH_INSTALLED_PATH%bin\pkg-config --modversion "%RELEASE_PATH%\lib\pkgconfig\gtk+-%API_VER%.pc" > libver.tmp || goto error
%OAH_INSTALLED_PATH%bin\pkg-config --variable=gtk_binary_version "%RELEASE_PATH%\lib\pkgconfig\gtk+-%API_VER%.pc" > libgtkbinver.tmp || goto error
set /P LIBVER= < libver.tmp
set /P GTKBINVER= < libgtkbinver.tmp
del libver.tmp
del libgtkbinver.tmp

nmake /nologo version=%LIBVER% api_ver=%API_VER% release_path=%RELEASE_PATH% bin_ver=%GTKBINVER% %*

goto:eof
:error
del libver.tmp
del libgtkbinver.tmp
echo Couldn't start build process... have you compiled Gtk+.sln with OAH_BUILD_OUTPUT cleared!??