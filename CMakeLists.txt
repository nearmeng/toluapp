cmake_minimum_required (VERSION 2.8)
project(toluapp)
set(CMAKE_VERBOSE_MAKEFILE ON)

get_filename_component (BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR} ABSOLUTE)
message(${BASE_DIR})

include_directories ( 
	${BASE_DIR}/inc
	${BASE_DIR}/3rd/lua53/inc
	${BASE_DIR}/src/bin
)
link_directories (
	${BASE_DIR}/lib
	${BASE_DIR}/3rd/lua53/lib
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BASE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BASE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BASE_DIR}/bin")

# Build lib
file (GLOB SRC_LIBTOLUAPP src/lib/*.c )

add_library (toluapp_lib STATIC ${SRC_LIBTOLUAPP})
target_link_libraries (toluapp_lib lua)
set_target_properties (toluapp_lib PROPERTIES OUTPUT_NAME toluapp CLEAN_DIRECT_OUTPUT 1)

# Build app
add_executable(toluapp_bootstrap
	src/bin/tolua.c
    src/bin/toluabind_default.c
)

if (MSVC)
    target_link_libraries (toluapp_bootstrap toluapp_lib lua)
else ()
    target_link_libraries (toluapp_bootstrap toluapp_lib lua m dl)
endif ()

add_dependencies(toluapp_bootstrap toluapp_lib)

file(GLOB LUA_FILES src/bin/lua/*.lua)

if (MSVC)
	set(TOLUAPP_BOOTSTRAP_EXE "${BASE_DIR}/bin/Debug/toluapp_bootstrap.exe")
else ()
	set(TOLUAPP_BOOTSTRAP_EXE "${BASE_DIR}/bin/toluapp_bootstrap")
endif ()

add_custom_command(OUTPUT ${BASE_DIR}/src/bin/toluabind.c
	COMMAND "${TOLUAPP_BOOTSTRAP_EXE}" -o "toluabind.c" tolua.pkg
	DEPENDS ${LUA_FILES}
	WORKING_DIRECTORY "${BASE_DIR}/src/bin/"
    COMMENT "Now Generating toluabind file"
)

add_executable(toluapp
	src/bin/tolua.c
    ${BASE_DIR}/src/bin/toluabind.c
)

if (MSVC)
    target_link_libraries (toluapp toluapp_lib lua)
else ()
    target_link_libraries (toluapp toluapp_lib lua m dl)
endif ()

if(UNIX)
	add_custom_target(toluabind ALL DEPENDS ${BASE_DIR}/src/bin/toluabind.c)
	add_dependencies(toluapp toluabind)
endif()

add_dependencies(toluapp toluapp_bootstrap)
