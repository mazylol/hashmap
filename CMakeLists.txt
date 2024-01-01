cmake_minimum_required(VERSION 3.22)
project(hashmap VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

add_custom_target(copy_keys
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/test/keys.txt
    ${CMAKE_BINARY_DIR}/keys.txt
    COMMENT "Copying keys to build directory"
)

add_custom_target(copy_values
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/test/values.txt
    ${CMAKE_BINARY_DIR}/values.txt
    COMMENT "Copying values to build directory"
)

add_executable(${PROJECT_NAME}_test test/test.cpp)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}_test copy_keys copy_values)