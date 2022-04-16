/*
 * Have to implement isA relationships which will guide the whole pipeline 
 * correctly into a better process. Better have syntactic iteration in place as
 * a completely different namesapce and semantic as a completely different one 
 * Pointwise Mutula Informace and other parameters must be checked with too
 */

#include <string>
#include <vector>
#include <regex>


namespace semantic_segmentation {
  
  
}

namespace syntactic_segmentation {

  // Credit : https://github.com/mmichelsonIF/hearst_patterns_python/blob/master/hearstPatterns/hearstPatterns.py
  
  static const std::vector<std::regex> Hearst_patterns {
    {
        std::regex(R"([^ (Mr)(Ms)]. )")
    }
  };

  inline std::vector<std::string> collect_strings (const std::string& lines) {
    std::smatch sm;
    std::vector<std::string> collected_strings {};

    // Better to remove this for slowdowns
    std::string s {lines};

    for ( const auto& pattern : Hearst_patterns) {
      while (std::regex_search(s, sm, pattern)) {
        collected_strings.push_back(sm.str());
        s = sm.suffix();
      }
    };
    return collected_strings;
  }


  // Simply prints a vector of strings
  void print_strings (const std::vector<std::string> & vect_of_str);
  
}
