cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(xacc-dwave LANGUAGES CXX)

set(CMAKE_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
message(STATUS "C++ version ${CXX_STANDARD} configured.")

# Make sure all build libraries have reference to their dependents
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(XACC REQUIRED)

set(CppMicroServicesConfig_DIR "${XACC_ROOT}/share/cppmicroservices3/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${XACC_ROOT}/share/xacc")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CppMicroServicesConfig_DIR}")
include(tests)
include(CppMicroServicesConfig)

find_package(Boost COMPONENTS system program_options filesystem chrono thread REQUIRED)

include_directories(${XACC_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${XACC_ROOT}/include/rapidjson/include)
include_directories(${XACC_ROOT}/include/eigen)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/accelerator)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/compiler)

link_directories(${XACC_LIBRARY_DIR})

add_subdirectory(accelerator)
add_subdirectory(compiler)
add_subdirectory(examples)

# Gather tests
file (GLOB test_files tests/DWQMI*.cpp)
add_tests("${test_files}" "${CMAKE_CURRENT_SOURCE_DIR}" "${Boost_LIBRARIES};${XACC_LIBRARIES};dl;pthread;xacc-dwave-qmicompiler")


