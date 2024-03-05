cmake_minimum_required(VERSION 3.5)
project(project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)

include_directories(${CMAKE_SOURCE_DIR}/include/classes)
include_directories(${CMAKE_SOURCE_DIR}/include/controllers)
include_directories(${CMAKE_SOURCE_DIR}/include/routes)
include_directories(${CMAKE_SOURCE_DIR}/include)


enable_testing()

file(GLOB_RECURSE SOURCES "src/*.cpp")


add_executable(project ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
