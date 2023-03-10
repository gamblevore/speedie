#!/bin/bash
echo "Started Building Speedie"
set -e
cd /usr/local/speedie/Library/CppLib

echo "Compiling /usr/local/lib/libjeebox.dylib"
g++ -o /usr/local/lib/libjeebox.dylib  -std=gnu++17 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -flto -D TARGET_UNIX=1 -D __SPEEDIE__=1 -arch=arm64  -arch=x86_64  -lc++ -dynamiclib -fPIC -D AS_LIBRARY=1   JB_FlowControl.cpp JB_File.cpp JB_ObjArray.cpp JB_MSR.cpp JB_LibraryFile.cpp JB_List.cpp JB_FastString.cpp JB_Dictionary.cpp JB_Child.cpp JB_Saveable.cpp JB_Compress.cpp JB_String.cpp JB_Utils.cpp JB_Main.cpp JB_Pipe.cpp JB_DivSufSort.cpp JB_Run.cpp JB_Vectors.cpp JB_ByteMap.cpp JB_RingTree.cpp JB_PNG.cpp JB_Date.cpp JB_Errors.cpp JB_DirReaderUnix.cpp JB_Math.cpp JB_DirReaderWin32.cpp JB_BasicIO.cpp JB_VM.cpp JB_Alloc.cpp JB_Tokeniser.cpp    /usr/local/speedie/jeebox.scproj/Cpp/JB.cpp   /usr/local/speedie/jeebox.scproj/Cpp/JB_Globals.cpp

echo "Compiling Speedie to /usr/local/speedie/Terminal/Speedie"
g++ -o /usr/local/speedie/Terminal/Speedie  -std=gnu++17 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -flto -D TARGET_UNIX=1 -D __SPEEDIE__=1 -arch=arm64  -arch=x86_64  -lc++  JB_FlowControl.cpp JB_File.cpp JB_ObjArray.cpp JB_MSR.cpp JB_LibraryFile.cpp JB_List.cpp JB_FastString.cpp JB_Dictionary.cpp JB_Child.cpp JB_Saveable.cpp JB_Compress.cpp JB_String.cpp JB_Utils.cpp JB_Main.cpp JB_Pipe.cpp JB_DivSufSort.cpp JB_Run.cpp JB_Vectors.cpp JB_ByteMap.cpp JB_RingTree.cpp JB_PNG.cpp JB_Date.cpp JB_Errors.cpp JB_DirReaderUnix.cpp JB_Math.cpp JB_DirReaderWin32.cpp JB_BasicIO.cpp JB_VM.cpp JB_Alloc.cpp JB_Tokeniser.cpp   -I /usr/local/speedie/Speedie.scproj/Build  /usr/local/speedie/Speedie.scproj/Build/JB.cpp  /usr/local/speedie/Speedie.scproj/Build/JB_Globals.cpp 


cd /usr/local/speedie/jeebox.scproj/Examples
echo "Creating directories"
echo "Creating dir Build"
mkdir -p "Build"
chmod 777 Build

echo "Creating dir /usr/local/include/"
mkdir -p "/usr/local/include/"
chmod 777 /usr/local/include/

echo "Creating dir /usr/local/bin/"
mkdir -p "/usr/local/bin/"
chmod 777 /usr/local/bin/


echo "Cleaning old files"
rm -rf Build/*

echo "Installing headers"
cp *.h /usr/local/include/
chmod 775 /usr/local/include/jeebox*

echo "Compiling jb.cpp"
g++ -o Build/jb  -std=gnu++17 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -flto -D TARGET_UNIX=1 -D __SPEEDIE__=1 -arch=arm64  -arch=x86_64  -lc++ -g -ljeebox  jb.cpp
echo "Compiling xml.cpp"
g++ -o Build/xml  -std=gnu++17 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -flto -D TARGET_UNIX=1 -D __SPEEDIE__=1 -arch=arm64  -arch=x86_64  -lc++ -g -ljeebox  xml.cpp
echo "Compiling test.cpp"
g++ -o Build/test  -std=gnu++17 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -flto -D TARGET_UNIX=1 -D __SPEEDIE__=1 -arch=arm64  -arch=x86_64  -lc++ -g -ljeebox  test.cpp
echo "Compiling users.cpp"
g++ -o Build/users  -std=gnu++17 -L/usr/local/lib/ -I /usr/local/include -I /usr/local/speedie/Library/CppLib -w -Wno-return-type-c-linkage -Os -ffast-math -flto -D TARGET_UNIX=1 -D __SPEEDIE__=1 -arch=arm64  -arch=x86_64  -lc++ -g -ljeebox  users.cpp

echo "Creating Links"
ln -sf /usr/local/speedie/Terminal/Speedie /usr/local/bin/spd
ln -sf /usr/local/speedie/Terminal/Speedie /usr/local/bin/speedie
echo ""
echo "Build Complete."

echo "Speedie Compiling Perry"
/usr/local/speedie/Terminal/Speedie /usr/local/speedie/Perry.scproj
