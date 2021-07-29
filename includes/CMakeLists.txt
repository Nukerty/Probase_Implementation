add_library(AcyDirGraphs 
  ConceptGraphs/adg.cpp 
  ConceptGraphs/adg.hpp
  )

target_include_directories(AcyDirGraphs PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

