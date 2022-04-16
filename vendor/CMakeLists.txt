find_package(PythonLibs 3 REQUIRED)
find_package(PythonInterp 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})


add_library(VendorLibs SHARED
  spacy/attrs.h
  spacy/attrs.cpp
  spacy/doc.h
  spacy/doc.cpp
  spacy/nlp.h
  spacy/nlp.cpp
  spacy/pyobjectptr.h
  spacy/pyobjectptr.cpp
  spacy/python.h
  spacy/spacy.h
  spacy/spacy.cpp
  spacy/span.h
  spacy/span.cpp
  spacy/stringstore.h
  spacy/stringstore.cpp
  spacy/token.h
  spacy/token.cpp
  spacy/vocab.h
  spacy/vocab.cpp
)

target_include_directories(VendorLibs PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
