#include "stream.hpp"

StreamHandler::FileHandler::FileHandler() {
  std::string FileName = "";
}

StreamHandler::FileHandler::~FileHandler() {
}

adg::TargettedGraph StreamHandler::FileHandler::ExtractTree(std::fstream fs,std::string filename) {
  adg::TargettedGraph Tree("");
  if (filename == "") {
    std::cout<<"Invalid file name\n";
    exit(1);
  }
  else if (fs.open(filename,std::ios::in); !fs.is_open()) {
    std::cout<<"Cannot open file : "<<filename<<"\n";
    exit(1);
  }
  
  // Otherwise extract from file
  std::cout<<"Opening file : "<<filename<<"\n";
  std::string line;
  std::string data;
  while (getline(fs,line)) {
    data += line + '\n';
  }

  fs.close();
  
  return Tree;

};
  


