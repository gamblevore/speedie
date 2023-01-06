# Build like this:
# cd </path/to/jeebox-master>
# cmake -BBuild .; cd Build; sudo make install

cmake_minimum_required(VERSION 3.13)
project(Jeebox VERSION 1.2.5 DESCRIPTION "Extensible and good looking data-format with lots of cool util functions")

if (UNIX AND NOT APPLE)
	set(LINUX TRUE)
elseif(APPLE)
	SET( CMAKE_CXX_COMPILER "c++" ) #more pointless issues to solve
endif()

set(Root ${CMAKE_SOURCE_DIR})
set(RootParent /)
cmake_path(GET Root PARENT_PATH RootParent)
#get_filename_component(PARENT_DIR ${RootParent} DIRECTORY)
set(JbCpp ${Root}/Cpp)
set(JbLib ${RootParent}/Library/CppLib)
set(Exmp ${Root}/Examples/)

message(Root="${Root}")
message(RootParent="${RootParent}")
message(JbCpp="${JbCpp}")
message(JbLib="${JbLib}")
message(Exmp="${Exmp}")

file(GLOB MainSrc ${JbLib}/*.cpp)
set(MainSrc ${MainSrc} ${JbCpp}/JB.cpp ${JbCpp}/JB_Globals.cpp)


set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

add_compile_definitions(TARGET_UNIX=1 AS_LIBRARY=1)
add_compile_options(${ARCH} ${DEBUG} -Wno-return-type-c-linkage -Wno-unused-value -Wno-unknown-escape-sequence -Wno-invalid-source-encoding -Wno-nonnull -Wno-nullability-completeness -std=gnu++14 -stdlib=libc++ -fno-strict-aliasing -fvisibility=hidden -march=core2 -mfpmath=sse -mmmx -msse -msse2 -msse4.1 -msse4.2 -mtune=native -Os -I ${JbLib})
add_link_options(${ARCH} -flto)

 
function (BuildLibrary Name Type Arch)
	add_library(${Name} 			   		${Type} ${MainSrc})
	set_target_properties(${Name}  			PROPERTIES VERSION ${PROJECT_VERSION})
	target_compile_options(${Name} PUBLIC ${Arch})
	set_target_properties(${Name} 			PROPERTIES PUBLIC_HEADER "${Exmp}jeebox_api.h;${Exmp}Jeebox.h")

	target_include_directories(${Name} 		PRIVATE ${JbCpp}/LibSrc)
	target_include_directories(${Name} 		PRIVATE ${JbLib}/)
	install(
		TARGETS ${Name}
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		RUNTIME DESTINATION bin
		PUBLIC_HEADER DESTINATION /usr/local/include
	)
endfunction()

BuildLibrary(JeeboxStatic STATIC "")        		    # 64-bit is the default
BuildLibrary(Jeebox SHARED "")
if (NOT LINUX) 
	BuildLibrary(JeeboxStatic_32 STATIC "-m32")			# just test that it works at all.
endif()



add_executable(example_xml ${Root}/Examples/xml.cpp)
target_link_libraries(example_xml JeeboxStatic) 		# test static

add_executable(example_test ${Root}/Examples/test.cpp)
target_link_libraries(example_test Jeebox)				# test dynamic

add_executable(example_userlist ${Root}/Examples/users.cpp)
target_link_libraries(example_userlist Jeebox)


add_executable(jb ${Root}/Examples/jb.cpp)
target_link_libraries(jb Jeebox)
install( TARGETS jb RUNTIME DESTINATION bin )


# add_executable(alloc_speed ${Root}/Examples/alloc_speed.cpp ${AllocSrc})
# target_compile_definitions(alloc_speed PUBLIC ALLOCATOR_ONLY=1) 	#seems to break everything?
# target_include_directories(alloc_speed 	PRIVATE ${JbCpp}/LibSrc)

