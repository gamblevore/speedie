#!/bin/bash
echo "Starting Speedie Build"
set -e
cd /usr/local/speedie/Library/CppLib


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

echo "Compiling Speedie to /usr/local/speedie/Terminal/Speedie"
g++ -o /usr/local/speedie/Terminal/Speedie  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -rdynamic  JB_File.cpp JB_Pico.cpp JB_MSR.cpp JB_LibraryFile.cpp JB_List.cpp JB_Temporal.cpp JB_FastString.cpp JB_Dictionary.cpp JB_Child.cpp JB_Saveable.cpp JB_Compress.cpp JB_String.cpp JB_Utils.cpp JB_Main.cpp JB_Pipe.cpp JB_Run.cpp JB_Vectors.cpp JB_PNG.cpp JB_Dylib.cpp JB_Date.cpp JB_Errors.cpp JB_DirReaderUnix.cpp JB_Math.cpp JB_DirReaderWin32.cpp JB_Array.cpp JB_BasicIO.cpp JB_VM.cpp JB_Alloc.cpp JB_Tokeniser.cpp   -I /usr/local/speedie/Speedie.scproj/Build  /usr/local/speedie/Speedie.scproj/Build/JB.cpp  /usr/local/speedie/Speedie.scproj/Build/JB_Globals.cpp -lrt -pthread
chmod 775 /usr/local/speedie/Terminal/Speedie
chown $U /usr/local/speedie/Terminal/Speedie


cd /usr/local/speedie/jeebox.scproj/Examples
echo "Creating directories"
echo "Creating dir Build"
mkdir -p "Build"
chmod 775 Build
chown $U Build

echo "Creating dir /usr/local/include/"
mkdir -p "/usr/local/include/"
chmod 775 /usr/local/include/
chown $U /usr/local/include/


echo "Cleaning old files"
rm -rf Build/* 2>/dev/null || true

echo "Installing headers"
cp    *.h /usr/local/include/
chmod 775 /usr/local/include/jeebox*
chown $U /usr/local/include/jeebox*

echo "Compiling jb.cpp"
g++ -o Build/jb  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -rdynamic -g -ljeebox  jb.cpp
chmod 775 Build/jb
chown $U Build/jb

echo "Compiling xml.cpp"
g++ -o Build/xml  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -rdynamic -g -ljeebox  xml.cpp
chmod 775 Build/xml
chown $U Build/xml

echo "Compiling test.cpp"
g++ -o Build/test  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -rdynamic -g -ljeebox  test.cpp
chmod 775 Build/test
chown $U Build/test

echo "Compiling users.cpp"
g++ -o Build/users  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -rdynamic -g -ljeebox  users.cpp
chmod 775 Build/users
chown $U Build/users


echo "Linking Speedie"

ln -sf /usr/local/speedie/Terminal/Speedie /usr/local/bin/spd
chmod 775 /usr/local/bin/spd
chown $U /usr/local/bin/spd


ln -sf /usr/local/speedie/Terminal/Speedie /usr/local/bin/speedie
chmod 775 /usr/local/bin/speedie
chown $U /usr/local/bin/speedie

/usr/local/speedie/Terminal/Speedie /usr/local/speedie/Cake.scproj --output_path=/usr/local/speedie/Terminal/Cake

echo "Linking Speedie"

ln -sf /usr/local/speedie/Terminal/Cake /usr/local/bin/cake
chmod 775 /usr/local/bin/cake
chown $U /usr/local/bin/cake


echo ""
echo "Build Complete."

#better to continue if libjeebox can't be compiled
set +e
cd /usr/local/speedie/Library/CppLib                         # allow source to be found!
/usr/local/bin/speedie /usr/local/speedie/jeebox.scproj -x   # regenerate libjeebox source
echo "Compiling /usr/local/lib/libjeebox.so for user '$U'"
g++ -o /usr/local/lib/libjeebox.so  -std=gnu++20 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -D TARGET_UNIX=1 -D __SPEEDIE__=1 -rdynamic -shared -fPIC -D AS_LIBRARY=1   JB_File.cpp JB_Pico.cpp JB_MSR.cpp JB_LibraryFile.cpp JB_List.cpp JB_Temporal.cpp JB_FastString.cpp JB_Dictionary.cpp JB_Child.cpp JB_Saveable.cpp JB_Compress.cpp JB_String.cpp JB_Utils.cpp JB_Main.cpp JB_Pipe.cpp JB_Run.cpp JB_Vectors.cpp JB_PNG.cpp JB_Dylib.cpp JB_Date.cpp JB_Errors.cpp JB_DirReaderUnix.cpp JB_Math.cpp JB_DirReaderWin32.cpp JB_Array.cpp JB_BasicIO.cpp JB_VM.cpp JB_Alloc.cpp JB_Tokeniser.cpp    /usr/local/speedie/jeebox.scproj/Cpp/JB.cpp   /usr/local/speedie/jeebox.scproj/Cpp/JB_Globals.cpp
chmod 775 /usr/local/lib/libjeebox.so
chown $U /usr/local/lib/libjeebox.so
set -e


echo "Speedie Compiling Perry (Optional Extra)"

echo "Getting GUI files that Perry needs"
sudo apt install libsdl2-dev
sudo apt install gedit

/usr/local/speedie/Terminal/Speedie /usr/local/speedie/Perry.scproj
