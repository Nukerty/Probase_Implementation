#include <iostream>

#include <ConceptGraphs/adg.hpp>

#ifdef USE_MYMATH
#   include "adg.hpp"
#endif

int main() {
  std::cout<<"Prog here"<<std::endl;
  adg::NodeTypeIndicator num = adg::NodeTypeIndicator::LeafNode;
  std::cout<<num<<std::endl;
}


