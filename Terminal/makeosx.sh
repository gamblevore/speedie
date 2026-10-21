#!/bin/bash
echo "Starting Speedie Build"
Speedie=$(dirname "$(realpath $0)")
Speedie=$(dirname "$(realpath $Speedie)")
echo "Building to $Speedie"
if [ "$Speedie" = "" ] ; then
	echo "failed to find speedie path"
	exit 1
fi
set -e
cd "$Speedie/Library/CppLib"


U="$SUDO_USER"
if [ "$U" = "" ]  ||  [ "$U" = "root" ] ; then
   U=$USER
fi
if [ "$U" = "" ]  ||  [ "$U" = "root" ] ; then
   U=$LOGNAME
fi
if [ "$U" = "" ]  ||  [ "$U" = "root" ] ; then
   U=$(basename -- "$HOME")
fi
if [ "$U" = "" ]  ||  [ "$U" = "root" ] ; then
   echo "Please set LOGNAME to the desired user's name so we can make these files and folders owned properly."
   exit 1
fi

echo "Compiling Speedie to $Speedie/Terminal/Speedie"
g++ -o $Speedie/Terminal/Speedietmp  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I $Speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -lc++  JB_File.cpp JB_Pico.cpp JB_MSR.cpp JB_LibraryFile.cpp JB_List.cpp JB_Temporal.cpp JB_FastString.cpp JB_Dictionary.cpp JB_Child.cpp JB_Compress.cpp JB_String.cpp JB_Utils.cpp JB_Main.cpp JB_Pipe.cpp JB_Run.cpp JB_Vectors.cpp JB_PNG.cpp JB_Dylib.cpp JB_Date.cpp JB_Errors.cpp JB_DirReaderUnix.cpp JB_Math.cpp FF_ARM64.S FF_Intel.S JB_DirReaderWin32.cpp JB_Array.cpp JB_BasicIO.cpp JB_VM.cpp JB_Alloc.cpp JB_Tokeniser.cpp   -I $Speedie/Speedie.scproj/Build  $Speedie/Speedie.scproj/Build/JB.cpp  $Speedie/Speedie.scproj/Build/JB_Globals.cpp 
mv $Speedie/Terminal/Speedietmp $Speedie/Terminal/Speedie
chmod 775 $Speedie/Terminal/Speedie
chown $U $Speedie/Terminal/Speedie


cd $Speedie/jeebox.scproj/Examples
echo "Creating directories"

if [ ! -f Build ]; then
    echo "Creating dir Build"
    mkdir -p "Build"
    chmod 775 Build
    chown $U Build
fi


if [ ! -f /usr/local/include/ ]; then
    echo "Creating dir /usr/local/include/"
    mkdir -p "/usr/local/include/"
    chmod 775 /usr/local/include/
    chown $U /usr/local/include/
fi


echo "Cleaning old files"
rm -rf Build/* 2>/dev/null || true

echo "Installing headers"
cp    *.h /usr/local/include/
chmod 775 /usr/local/include/jeebox*
chown $U /usr/local/include/jeebox*

set +e									# better to continue
echo "Symlinking Speedie"

ln -sf $Speedie/Terminal/Speedie /usr/local/bin/spd
chmod 775 /usr/local/bin/spd
chown $U /usr/local/bin/spd


ln -sf $Speedie/Terminal/Speedie /usr/local/bin/speedie
chmod 775 /usr/local/bin/speedie
chown $U /usr/local/bin/speedie



echo ""
cd $Speedie/Library/CppLib				# allow source to be found!

echo "Preparing libJeebox"
$Speedie/Terminal/Speedie $Speedie/jeebox.scproj -x		# regenerate libjeebox source

echo "Relaxing permissions"

chmod 775 ../../jeebox.scproj/Cpp/*
chown $U ../../jeebox.scproj/Cpp/*
chmod 775 ../../jeebox.scproj/Build/*
chown $U ../../jeebox.scproj/Build/*
echo "Compiling /usr/local/lib/libjeebox.dylib for user '$U'"

g++ -o /usr/local/lib/libjeebox.dylib  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I $Speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -lc++ -dynamiclib -fPIC -D AS_LIBRARY=1   JB_File.cpp JB_Pico.cpp JB_MSR.cpp JB_LibraryFile.cpp JB_List.cpp JB_Temporal.cpp JB_FastString.cpp JB_Dictionary.cpp JB_Child.cpp JB_Compress.cpp JB_String.cpp JB_Utils.cpp JB_Main.cpp JB_Pipe.cpp JB_Run.cpp JB_Vectors.cpp JB_PNG.cpp JB_Dylib.cpp JB_Date.cpp JB_Errors.cpp JB_DirReaderUnix.cpp JB_Math.cpp FF_ARM64.S FF_Intel.S JB_DirReaderWin32.cpp JB_Array.cpp JB_BasicIO.cpp JB_VM.cpp JB_Alloc.cpp JB_Tokeniser.cpp    $Speedie/jeebox.scproj/Cpp/JB.cpp   $Speedie/jeebox.scproj/Cpp/JB_Globals.cpp
chmod 775 /usr/local/lib/libjeebox.dylib
chown $U /usr/local/lib/libjeebox.dylib


cd $Speedie/jeebox.scproj/Examples
echo "Compiling jb.cpp"
g++ -o Build/jb  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I $Speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -lc++ -g -ljeebox  jb.cpp
chmod 775 Build/jb
chown $U Build/jb

echo "Compiling xml.cpp"
g++ -o Build/xml  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I $Speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -lc++ -g -ljeebox  xml.cpp
chmod 775 Build/xml
chown $U Build/xml

echo "Compiling test.cpp"
g++ -o Build/test  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I $Speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -lc++ -g -ljeebox  test.cpp
chmod 775 Build/test
chown $U Build/test

echo "Compiling users.cpp"
g++ -o Build/users  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I $Speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -lc++ -g -ljeebox  users.cpp
chmod 775 Build/users
chown $U Build/users



set -e


echo "Compiling Cake and Perry"
if [ ! -f "/usr/local/include/SDL2/SDL.h" ]; then
	echo "Please install SDL2 to get Perry and Cake to compile. Speedie expects SDL2 headers at /usr/local/include/SDL2/SDL.h"
	echo "https://wiki.libsdl.org/SDL2/Installation contains the guidelines."

else

echo "Making 🎂 Cake 🎂"
$Speedie/Terminal/Speedie $Speedie/Cake.scproj --output_path=$Speedie/Terminal/Cake

echo "Symlinking 🎂"

ln -sf $Speedie/Terminal/Cake /usr/local/bin/cake
chmod 775 /usr/local/bin/cake
chown $U /usr/local/bin/cake


ln -sf $Speedie/Terminal/Cake /usr/local/bin/🎂
chmod 775 /usr/local/bin/🎂
chown $U /usr/local/bin/🎂



echo "Making Perry"
$Speedie/Terminal/Speedie $Speedie/Perry.scproj

fi
