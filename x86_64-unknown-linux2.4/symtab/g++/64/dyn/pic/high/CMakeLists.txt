# CMakeLists for symtab/g++/64/dyn/pic/high
set (CMAKE_C_FLAGS "${TEST_DEFINES} -I${PROJECT_SOURCE_DIR}/testsuite/src -I${PROJECT_SOURCE_DIR}/testsuite/src/symtab ${CXXFLAGS} -DSOLO_MUTATEE ${MUTATEE_CXXFLAGS_GNU}   -O2 -fPIC")
set (CMAKE_C_FLAGS_DEBUG "")
set (CMAKE_C_FLAGS_RELEASE "")
set (CMAKE_C_COMPILE_OBJECT "${M_gnu_cxx} -c <FLAGS> -o <OBJECT> -c <SOURCE>")
set (CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})
set (CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
set (CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
set (CMAKE_CXX_COMPILE_OBJECT ${CMAKE_C_COMPILE_OBJECT})
set (CMAKE_EXE_LINKER_FLAGS "${MUTATEE_LDFLAGS_GNU}  -Wl,-export-dynamic")
include (../../../../../../srclists.cmake)
add_executable (symtab_group_test.dyn_g++_64_pic_high ${SOURCE_LIST_50})
target_link_libraries (symtab_group_test.dyn_g++_64_pic_high testA)
add_executable (test_exception.dyn_g++_64_pic_high ${SOURCE_LIST_69})


INSTALL (TARGETS
		symtab_group_test.dyn_g++_64_pic_high
		test_exception.dyn_g++_64_pic_high
	DESTINATION testsuite)
