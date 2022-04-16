add_library(AcyDirGraphs 
  ConceptGraphs/adg.cpp 
  ConceptGraphs/adg.hpp
  ConceptGraphs/math.cpp
  ConceptGraphs/math.hpp
  ConceptGraphs/stream.hpp
  ConceptGraphs/stream.cpp
  )

add_library(Util
  Util/file.hpp
  Util/file.cpp
  )

target_include_directories(AcyDirGraphs PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Util PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
