cmake_minimum_required (VERSION 2.8)
project(test_proj)

get_filename_component (BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)
message(${BASE_DIR})

include_directories ( 
	${BASE_DIR}/inc
	${BASE_DIR}/3rd/lua53/inc
)
link_directories (
	${BASE_DIR}/lib
	${BASE_DIR}/3rd/lua53/lib
)

# Build app
if (MSVC)
	set(TOLUAPP_EXE "${BASE_DIR}/bin/Debug/toluapp.exe")
else ()
	set(TOLUAPP_EXE "${BASE_DIR}/bin/toluapp")
endif ()

add_custom_command(OUTPUT ${BASE_DIR}/example/tolua_test.cpp
	COMMAND "${TOLUAPP_EXE}" -e -o "tolua_test.cpp" test.pkg
	WORKING_DIRECTORY "${BASE_DIR}/example/"
    COMMENT "Now Generating example pkg"
)

add_executable(toluapp_test
	test.cpp
    ${BASE_DIR}/example/tolua_test.cpp
)

if (MSVC)
    target_link_libraries (toluapp_test toluapp lua)
else ()
    target_link_libraries (toluapp_test toluapp lua m dl)
endif ()

if(UNIX)
	add_custom_target(tolua_pkg ALL DEPENDS ${BASE_DIR}/example/tolua_test.cpp)
	add_dependencies(toluapp_test tolua_pkg)
endif()

