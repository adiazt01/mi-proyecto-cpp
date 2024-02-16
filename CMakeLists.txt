cmake_minimum_required(VERSION 3.5)
project(project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
include_directories(${CMAKE_SOURCE_DIR}/include/classes)

enable_testing()


add_executable(project src/main.cpp src/classes/product.cpp src/classes/menu.cpp src/classes/productList.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
