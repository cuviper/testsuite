# CMakeLists for dyninst/icc/32/dyn/pic/none
set (CMAKE_C_FLAGS "${MUTATOR_DEFINES}  ${CFLAGS} ${MUTATEE_CFLAGS_GNU}   -g -O0 -fPIC")
set (CMAKE_C_FLAGS_DEBUG "")
set (CMAKE_C_FLAGS_RELEASE "")
set (CMAKE_C_FLAGS_RELWITHDEBINFO "")
set (CMAKE_C_COMPILER "${M_intel_cc}")
include_directories("${PROJECT_SOURCE_DIR}/testsuite/src")
include_directories("${PROJECT_SOURCE_DIR}/testsuite/src/dyninst")
add_definitions(-DSOLO_MUTATEE)
set (CMAKE_EXE_LINKER_FLAGS "${MUTATEE_LDFLAGS_GNU}  -Xlinker -export-dynamic")
IF (NOT ${M_intel_cc} MATCHES "NOTFOUND")
CHECK_MUTATEE_COMPILER ("${M_intel_cc}"
	"${MUTATOR_DEFINES}  ${CFLAGS} ${MUTATEE_CFLAGS_GNU}   -g -O0 -fPIC"
	"${MUTATEE_LDFLAGS_GNU}  -Xlinker -export-dynamic"
	"C"
	"intel_cc 32 dyn"
	MUTATEEintelcc32dynC)

IF (MUTATEEintelcc32dynC MATCHES "1")
include (${PROJECT_SOURCE_DIR}/i386-unknown-linux2.4/srclists.cmake)
if(TARGET dyninstAPI)
add_executable (dyninst_group_test.dyn_icc_32_pic_none ${SOURCE_LIST_69})
foreach (f ${SOURCE_LIST_69})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(dyninst_group_test.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (dyninst_group_test.dyn_icc_32_pic_none ${CMAKE_DL_LIBS})
add_executable (init_fini_callback.dyn_icc_32_pic_none ${SOURCE_LIST_74})
foreach (f ${SOURCE_LIST_74})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(init_fini_callback.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (init_fini_callback.dyn_icc_32_pic_none ${CMAKE_DL_LIBS})
add_executable (test1_12.dyn_icc_32_pic_none ${SOURCE_LIST_78})
foreach (f ${SOURCE_LIST_78})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test1_12.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test1_14.dyn_icc_32_pic_none ${SOURCE_LIST_70})
foreach (f ${SOURCE_LIST_70})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test1_14.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test1_19.dyn_icc_32_pic_none ${SOURCE_LIST_39})
foreach (f ${SOURCE_LIST_39})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test1_19.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test1_29.dyn_icc_32_pic_none ${SOURCE_LIST_58})
foreach (f ${SOURCE_LIST_58})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test1_29.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test1_35.dyn_icc_32_pic_none ${SOURCE_LIST_91})
foreach (f ${SOURCE_LIST_91})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test1_35.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test1_40.dyn_icc_32_pic_none ${SOURCE_LIST_47})
foreach (f ${SOURCE_LIST_47})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test1_40.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test1_41.dyn_icc_32_pic_none ${SOURCE_LIST_83})
foreach (f ${SOURCE_LIST_83})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test1_41.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test2_14.dyn_icc_32_pic_none ${SOURCE_LIST_75})
foreach (f ${SOURCE_LIST_75})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test2_14.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test2_6.dyn_icc_32_pic_none ${SOURCE_LIST_0})
foreach (f ${SOURCE_LIST_0})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test2_6.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (test2_6.dyn_icc_32_pic_none ${CMAKE_DL_LIBS})
add_executable (test2_8.dyn_icc_32_pic_none ${SOURCE_LIST_64})
foreach (f ${SOURCE_LIST_64})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test2_8.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test3_1.dyn_icc_32_pic_none ${SOURCE_LIST_43})
foreach (f ${SOURCE_LIST_43})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test3_1.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test3_2.dyn_icc_32_pic_none ${SOURCE_LIST_46})
foreach (f ${SOURCE_LIST_46})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test3_2.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test3_3.dyn_icc_32_pic_none ${SOURCE_LIST_96})
foreach (f ${SOURCE_LIST_96})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test3_3.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test3_4.dyn_icc_32_pic_none ${SOURCE_LIST_54})
foreach (f ${SOURCE_LIST_54})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test3_4.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test3_5.dyn_icc_32_pic_none ${SOURCE_LIST_94})
foreach (f ${SOURCE_LIST_94})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test3_5.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test3_6.dyn_icc_32_pic_none ${SOURCE_LIST_33})
foreach (f ${SOURCE_LIST_33})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test3_6.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test3_7.dyn_icc_32_pic_none ${SOURCE_LIST_82})
foreach (f ${SOURCE_LIST_82})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test3_7.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test4_1.dyn_icc_32_pic_none ${SOURCE_LIST_1})
foreach (f ${SOURCE_LIST_1})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test4_1.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test4_2.dyn_icc_32_pic_none ${SOURCE_LIST_56})
foreach (f ${SOURCE_LIST_56})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test4_2.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test4_3.dyn_icc_32_pic_none ${SOURCE_LIST_103})
foreach (f ${SOURCE_LIST_103})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test4_3.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test4_3b.dyn_icc_32_pic_none ${SOURCE_LIST_31})
foreach (f ${SOURCE_LIST_31})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test4_3b.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test4_4.dyn_icc_32_pic_none ${SOURCE_LIST_50})
foreach (f ${SOURCE_LIST_50})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test4_4.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test4_4b.dyn_icc_32_pic_none ${SOURCE_LIST_67})
foreach (f ${SOURCE_LIST_67})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test4_4b.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_callback_1.dyn_icc_32_pic_none ${SOURCE_LIST_62})
foreach (f ${SOURCE_LIST_62})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_callback_1.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_callback_2.dyn_icc_32_pic_none ${SOURCE_LIST_66})
foreach (f ${SOURCE_LIST_66})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_callback_2.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_10.dyn_icc_32_pic_none ${SOURCE_LIST_71})
foreach (f ${SOURCE_LIST_71})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_10.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_11.dyn_icc_32_pic_none ${SOURCE_LIST_88})
foreach (f ${SOURCE_LIST_88})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_11.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_12.dyn_icc_32_pic_none ${SOURCE_LIST_6})
foreach (f ${SOURCE_LIST_6})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_12.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_13.dyn_icc_32_pic_none ${SOURCE_LIST_59})
foreach (f ${SOURCE_LIST_59})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_13.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_14.dyn_icc_32_pic_none ${SOURCE_LIST_95})
foreach (f ${SOURCE_LIST_95})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_14.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_5.dyn_icc_32_pic_none ${SOURCE_LIST_28})
foreach (f ${SOURCE_LIST_28})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_5.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_6.dyn_icc_32_pic_none ${SOURCE_LIST_7})
foreach (f ${SOURCE_LIST_7})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_6.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_7.dyn_icc_32_pic_none ${SOURCE_LIST_40})
foreach (f ${SOURCE_LIST_40})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_7.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_8.dyn_icc_32_pic_none ${SOURCE_LIST_24})
foreach (f ${SOURCE_LIST_24})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_8.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_fork_9.dyn_icc_32_pic_none ${SOURCE_LIST_48})
foreach (f ${SOURCE_LIST_48})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_fork_9.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_mem_1.dyn_icc_32_pic_none ${SOURCE_LIST_19})
foreach (f ${SOURCE_LIST_19})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_mem_1.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_mem_2.dyn_icc_32_pic_none ${SOURCE_LIST_18})
foreach (f ${SOURCE_LIST_18})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_mem_2.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_mem_3.dyn_icc_32_pic_none ${SOURCE_LIST_22})
foreach (f ${SOURCE_LIST_22})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_mem_3.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_mem_4.dyn_icc_32_pic_none ${SOURCE_LIST_32})
foreach (f ${SOURCE_LIST_32})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_mem_4.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_mem_5.dyn_icc_32_pic_none ${SOURCE_LIST_34})
foreach (f ${SOURCE_LIST_34})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_mem_5.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_mem_6.dyn_icc_32_pic_none ${SOURCE_LIST_16})
foreach (f ${SOURCE_LIST_16})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_mem_6.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_mem_7.dyn_icc_32_pic_none ${SOURCE_LIST_37})
foreach (f ${SOURCE_LIST_37})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_mem_7.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_mem_8.dyn_icc_32_pic_none ${SOURCE_LIST_9})
foreach (f ${SOURCE_LIST_9})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_mem_8.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_snip_remove.dyn_icc_32_pic_none ${SOURCE_LIST_72})
foreach (f ${SOURCE_LIST_72})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_snip_remove.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_stack_1.dyn_icc_32_pic_none ${SOURCE_LIST_25})
foreach (f ${SOURCE_LIST_25})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_stack_1.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_stack_2.dyn_icc_32_pic_none ${SOURCE_LIST_26})
foreach (f ${SOURCE_LIST_26})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_stack_2.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_stack_3.dyn_icc_32_pic_none ${SOURCE_LIST_98})
foreach (f ${SOURCE_LIST_98})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_stack_3.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_stack_4.dyn_icc_32_pic_none ${SOURCE_LIST_85})
foreach (f ${SOURCE_LIST_85})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_stack_4.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
add_executable (test_thread_1.dyn_icc_32_pic_none ${SOURCE_LIST_15})
foreach (f ${SOURCE_LIST_15})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_thread_1.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (test_thread_1.dyn_icc_32_pic_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (test_thread_2.dyn_icc_32_pic_none ${SOURCE_LIST_90})
foreach (f ${SOURCE_LIST_90})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_thread_2.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (test_thread_2.dyn_icc_32_pic_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (test_thread_3.dyn_icc_32_pic_none ${SOURCE_LIST_61})
foreach (f ${SOURCE_LIST_61})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_thread_3.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (test_thread_3.dyn_icc_32_pic_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (test_thread_5.dyn_icc_32_pic_none ${SOURCE_LIST_86})
foreach (f ${SOURCE_LIST_86})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_thread_5.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (test_thread_5.dyn_icc_32_pic_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (test_thread_6.dyn_icc_32_pic_none ${SOURCE_LIST_36})
foreach (f ${SOURCE_LIST_36})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_thread_6.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (test_thread_6.dyn_icc_32_pic_none ${CMAKE_THREAD_LIBS_INIT})
add_executable (test_thread_7.dyn_icc_32_pic_none ${SOURCE_LIST_29})
foreach (f ${SOURCE_LIST_29})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_thread_7.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (test_thread_7.dyn_icc_32_pic_none ${CMAKE_THREAD_LIBS_INIT})
add_executable (test_thread_8.dyn_icc_32_pic_none ${SOURCE_LIST_5})
foreach (f ${SOURCE_LIST_5})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(test_thread_8.dyn_icc_32_pic_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (test_thread_8.dyn_icc_32_pic_none ${CMAKE_THREAD_LIBS_INIT})


INSTALL (TARGETS
		dyninst_group_test.dyn_icc_32_pic_none
		init_fini_callback.dyn_icc_32_pic_none
		test1_12.dyn_icc_32_pic_none
		test1_14.dyn_icc_32_pic_none
		test1_19.dyn_icc_32_pic_none
		test1_29.dyn_icc_32_pic_none
		test1_35.dyn_icc_32_pic_none
		test1_40.dyn_icc_32_pic_none
		test1_41.dyn_icc_32_pic_none
		test2_14.dyn_icc_32_pic_none
		test2_6.dyn_icc_32_pic_none
		test2_8.dyn_icc_32_pic_none
		test3_1.dyn_icc_32_pic_none
		test3_2.dyn_icc_32_pic_none
		test3_3.dyn_icc_32_pic_none
		test3_4.dyn_icc_32_pic_none
		test3_5.dyn_icc_32_pic_none
		test3_6.dyn_icc_32_pic_none
		test3_7.dyn_icc_32_pic_none
		test4_1.dyn_icc_32_pic_none
		test4_2.dyn_icc_32_pic_none
		test4_3.dyn_icc_32_pic_none
		test4_3b.dyn_icc_32_pic_none
		test4_4.dyn_icc_32_pic_none
		test4_4b.dyn_icc_32_pic_none
		test_callback_1.dyn_icc_32_pic_none
		test_callback_2.dyn_icc_32_pic_none
		test_fork_10.dyn_icc_32_pic_none
		test_fork_11.dyn_icc_32_pic_none
		test_fork_12.dyn_icc_32_pic_none
		test_fork_13.dyn_icc_32_pic_none
		test_fork_14.dyn_icc_32_pic_none
		test_fork_5.dyn_icc_32_pic_none
		test_fork_6.dyn_icc_32_pic_none
		test_fork_7.dyn_icc_32_pic_none
		test_fork_8.dyn_icc_32_pic_none
		test_fork_9.dyn_icc_32_pic_none
		test_mem_1.dyn_icc_32_pic_none
		test_mem_2.dyn_icc_32_pic_none
		test_mem_3.dyn_icc_32_pic_none
		test_mem_4.dyn_icc_32_pic_none
		test_mem_5.dyn_icc_32_pic_none
		test_mem_6.dyn_icc_32_pic_none
		test_mem_7.dyn_icc_32_pic_none
		test_mem_8.dyn_icc_32_pic_none
		test_snip_remove.dyn_icc_32_pic_none
		test_stack_1.dyn_icc_32_pic_none
		test_stack_2.dyn_icc_32_pic_none
		test_stack_3.dyn_icc_32_pic_none
		test_stack_4.dyn_icc_32_pic_none
		test_thread_1.dyn_icc_32_pic_none
		test_thread_2.dyn_icc_32_pic_none
		test_thread_3.dyn_icc_32_pic_none
		test_thread_5.dyn_icc_32_pic_none
		test_thread_6.dyn_icc_32_pic_none
		test_thread_7.dyn_icc_32_pic_none
		test_thread_8.dyn_icc_32_pic_none
	DESTINATION ${INSTALL_DIR})

ENDIF()
ENDIF()
ENDIF()
