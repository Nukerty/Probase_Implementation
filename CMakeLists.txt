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
  add_subdirectory(vendor)
endif()

# add the executable
add_executable(Probase_clone main.cpp)

# Spacy that is required 
find_library(LIB_SPACY spacy)
target_link_libraries(Probase_clone PUBLIC ${LIB_SPACY})
message("Probase succesfully loaded")
 
if (UNIX)
  # include_directories("/usr/include/python3.10")
  # add_definitions("-lspacy")
  find_package(PythonLibs REQUIRED)
  include_directories(${PYTHON_INCLUDE_DIRS})
  target_link_libraries(Probase_clone PUBLIC ${PYTHON_LIBRARIES})
  message("Python important directory has been included")
  # Compile flags
  add_compile_options(-Wall -Wextra -pedantic -Wextra) 
endif (UNIX)

if (WIN32)
  add_compile_options(/W4 /WX) 
endif (WIN32)

if (MSVC)
  add_compile_options(/W4 /WX) 
endif (MSVC)

#fmt
find_package(fmt REQUIRED)
include_directories(${fmt_INCLUDE_DIRS})
target_link_libraries(Probase_clone PUBLIC fmt::fmt)


# linking custom library
if(USE_MYMATH)
target_link_libraries(Probase_clone PUBLIC AcyDirGraphs)
target_link_libraries(Probase_clone PUBLIC Util)
# target_link_libraries(Probase_clone PUBLIC VendorLibs)
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

# Tests
# enable_testing()
# include_directories("src")
# set(LIB_HEADERS "src/spacy/spacy")
# set(TEST_HEADERS "tests/unittest.h")
#
# function(add_spacy_test target)
#
#   add_executable(test_link_${target} tests/test_${target}.cpp)
#   target_link_libraries(test_link_${target} spacy)
#   add_test(test_link_${target} "${PROJECT_BINARY_DIR}/test_link_${target}")
#
#   add_executable(test_header_${target} tests/test_${target}.cpp)
#   target_compile_definitions(test_header_${target} PRIVATE SPACY_HEADER_ONLY=1)
#   target_link_libraries(test_header_${target} ${PYTHON_LIBRARIES})
#   add_test(test_header_${target} "${PROJECT_BINARY_DIR}/test_header_${target}")
#
# endfunction()
#
# add_spacy_test(spacy)
# add_spacy_test(attrs)
# add_spacy_test(nlp)
# add_spacy_test(doc)
# add_spacy_test(vocab)
# add_spacy_test(stringstore)
# add_spacy_test(span)
# add_spacy_test(token)
