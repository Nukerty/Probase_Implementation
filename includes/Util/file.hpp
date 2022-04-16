/** 
 *  @file   file.hpp
 *  @brief  File Handler Interface
 *  @author nkb
 *  @date   2021-12-23
 ***********************************************/
#include <fstream>
#include <string>
#include <stdexcept>

/*
 * @brief Filecodes for custom access handling
 */
enum filecodes {
  FILE_ERROR_OPENING      = 141,
  FILE_ERROR_ACCESSING    = 142,
  FILE_ERROR_CLOSING      = 143,
};

namespace fileHandler {
 
  /*
   * Class to handle file
   */
  class FileHandler {
   
  public:
    /* 
     * @brief Constructor for File Handling
     */
    FileHandler();

    /* 
     * @brief Parameterized Constructor for File Handling
     * @param[in] filename Filename/Path of the file to handle
     */
    FileHandler(std::string filename); 
    /*
     * @brief Set file opener to open file
     */
    void SetFile(std::string filename) {
      _filename = filename;
      _file.open(_filename, _file.in | _file.out);
      if (!_file.is_open()) throw FILE_ERROR_OPENING;
    }

    /*
     * @brief GetCurrentLine number
     * @return Returns the number of line we are at and total
     */
    std::string CountStatus();

    /*
     * @brief Get a single line from the file
     * @note Should have a static/constexpr handler at some point
     * @return Returns a line from the file
     */
    std::string GetLine();

    /*
     * @brief Get N lines from the file
     * @details
     * If the lines current line index exceeds the current file then returns
     * back with -1. And closes the File object
     * @note Should have a static/constexpr handler at some point
     * @return Returns n-lines from the file
     */
    std::string GetnLines(int number);

    /*
     * @brief Get all lines from the file
     * @note Should have a static/constexpr handler at some point
     * @return Returns all lines from the file
     */
    std::string GetAllLines();

    /* 
     * @brief Destructor for File Handler
     */
    ~FileHandler();

    /*
     * @brief Deleting copy constructor and assignment
     */
    FileHandler(const FileHandler & copy) = delete;
    FileHandler& operator=(const FileHandler& copy) = delete;

  private:
    int current_line {};        // Current line that the file is being read on
    int no_of_lines {};         // Total number of lines in the document
    std::string _filename {};   // Filename / Path of the file
    std::fstream _file;         // Handles the file stream
  };

}
