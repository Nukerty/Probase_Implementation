#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "adg.hpp"

namespace StreamHandler {

  /*
   * Handling TargettedGraph object conversion from file and back using the 
   * StreamHandler::FileHandler class
   */
  std::fstream fpoint;

  class FileHandler {
    
    static std::string FileName;

    FileHandler();
    ~FileHandler(); 

    adg::TargettedGraph ExtractTree (std::fstream fs, std::string filename);
    void SaveTree(adg::TargettedGraph);

  };

};
