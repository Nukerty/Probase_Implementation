#include <iostream>
#include <vector>

#include <ConceptGraphs/adg.hpp>
#include <ConceptGraphs/stream.hpp>

#ifdef USE_MYMATH
#   include <ConceptGraphs/adg.hpp>
#endif

int main() {
  std::cout<<"Prog here"<<std::endl;
  adg::NodeTypeIndicator num = adg::NodeTypeIndicator::LeafNode;
  std::cout<<num<<std::endl;

  // run_tests();
  adg::TargettedGraph Tree("Test_concept");

  std::cout<<"TargettedGraphName : "<< Tree.GraphName 
    <<"\tTargettedGraph ID : "<<Tree.ReturnID()<<"\n";
  
}


