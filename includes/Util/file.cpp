#include "file.hpp"

#include <fstream>
#include <string>
#include <fmt/core.h>
#include <iterator>

namespace fileHandler {

  FileHandler::FileHandler() : _filename {} {}

  FileHandler::FileHandler(std::string filename) : _filename {filename} {
    _file.open(_filename, _file.in | _file.out);
    if (!_file.is_open()) {throw FILE_ERROR_OPENING;}
    no_of_lines = std::count(std::istreambuf_iterator<char>(_file),
               std::istreambuf_iterator<char>(), '\n');
    current_line = 0;
  };

 
  std::string FileHandler::CountStatus() {
    return fmt::format("Line number : {}\nTotal number of lines : {}\n",
        current_line, no_of_lines);
  }


 std::string FileHandler::GetLine() {
    std::string data{};
    char chr;
    while (_file >> chr, chr!='\n' || chr!=_file.eof()) {
      data+=chr;
    }
    if (chr == _file.eof()) fmt::print("End of file reached");
    else current_line += 1;
    
    return data;
  }

  std::string FileHandler::GetnLines(int number) {
    std::string data{};
    char chr;
    int num {number};

    for (int i = 0; i < num && chr!=_file.eof(); ++i) {
    while (_file >> chr, chr!='\n' || chr!=_file.eof())
      data+=chr;
    data+='\n';
    current_line += 1; }
    
    return data;
  }

  std::string FileHandler::GetAllLines() {
    std::string data{};
    char chr;

    while (_file >> chr, chr!=_file.eof())
      data+=chr;
    data+='\n';

    // Seeking back to the original line
    _file.seekg(std::ios::beg);
    for(int i=0; i < current_line - 1; ++i){
        _file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return data;
  }

  FileHandler::~FileHandler() {
    if (_file.is_open()) {_file.close();}
  };

}
