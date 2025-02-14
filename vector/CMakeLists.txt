cmake_minimum_required(VERSION 3.20)

project(STLite)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

enable_testing()

include_directories(src)
include_directories(data)

set(files_prefix "${CMAKE_CURRENT_SOURCE_DIR}/data")
file(GLOB_RECURSE CPPs "${files_prefix}/**.cpp")

foreach(cpp_file ${CPPs})
    string(REPLACE "/code.cpp" "" testname ${cpp_file})
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/data/" "" testname ${testname})
    add_executable(${testname} ${files_prefix}/${testname}/code.cpp)
    add_test(NAME test_${testname}
            # COMMAND $<TARGET_FILE:${testname}>)
            COMMAND bash -c "$<TARGET_FILE:${testname}> | diff ${files_prefix}/${testname}/answer.txt -")
endforeach()