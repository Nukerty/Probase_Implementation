cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure header file to pass in to source code
configure_file(config.h.in config.h)

# set the project name and options
project(Probase_clone VERSION 0.1)
option(USE_MYMATH "Use custom math implementation" ON)
option(INSTALL_TO_DIR "Install implementation to system" OFF)
option(TEST_TARGETS "Testing Targets" OFF)

if(USE_MYMATH)
  add_subdirectory(includes)
endif()

# add the executable
add_executable(Probase_clone main.cpp)

# linking custom library
if(USE_MYMATH)
target_link_libraries(Probase_clone PUBLIC AcyDirGraphs)
endif()

if(INSTALL_TO_DIR)
  install(TARGETS "${PROJECT_NAME}" DESTINATION bin)    #${CMAKE_INSTALL_PREFIX}/bin
  install(FILES "${main.cpp}" DESTIONATION src)         #${CMAKE_INSTALL_PREFIX}/src
endif()

# if(TEST_TARGETS)
#   include(CTest)
#   add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/
# 
# endif()

