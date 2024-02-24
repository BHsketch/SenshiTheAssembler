cmake_minimum_required(VERSION 3.25.1)

project (Senshi)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir_lex "${PROJECT_SOURCE_DIR}/src/lexer/")
set (source_dir_assembler "${PROJECT_SOURCE_DIR}/src/assembler/")
set (source_dir_main "${PROJECT_SOURCE_DIR}/src/main/")

set (include_dir_lex "${PROJECT_SOURCE_DIR}/include/lex")
set (include_dir_assembler "${PROJECT_SOURCE_DIR}/include/assembler")

file (GLOB source_files  "${source_dir_lex}/*.cpp" "${source_dir_assembler}/*.cpp"  "${source_dir_main}/*.cpp")
file (GLOB header_files "${include_dir_lex}/*.h" "${include_dir_assembler}/*.h"  "${include_dir_main}/*.h" )

add_executable (${PROJECT_NAME} ${header_files} ${source_files})

target_include_directories(${PROJECT_NAME} PRIVATE ${include_dir_lex} ${include_dir_assembler})
