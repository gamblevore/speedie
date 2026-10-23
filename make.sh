#!/bin/bash

set -e
Speedie=$(dirname "$(realpath $0)")
NativeFlags="-lrt"

if [ "$Speedie" = "" ] ; then
	echo "failed to find speedie path"
	exit 1
fi
if [ $(uname) = "Darwin" ] ; then
	NativeFlags=""
	echo "Building Speedie for OSX: $Speedie/Terminal/Speedie"
else
	echo "Building Speedie for Linux: $Speedie/Terminal/Speedie"
fi

cd "$Speedie/Library/CppLib"
g++  -o  $Speedie/Terminal/Speedietmp  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I $Speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1  $NativeFlags  *.cpp *.S  -I $Speedie/Speedie.scproj/Build  $Speedie/Speedie.scproj/Build/JB.cpp  $Speedie/Speedie.scproj/Build/JB_Globals.cpp
mv $Speedie/Terminal/Speedietmp $Speedie/Terminal/Speedie

echo "Running post_install.spd"
$Speedie/Terminal/Speedie $Speedie/Terminal/post_install.spd
