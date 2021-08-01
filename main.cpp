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

 /* std::cout<<"TargettedGraphName : "<< Tree.GraphName 
    <<"\tTargettedGraph ID : "<<Tree.ReturnID()<<"\n";*/

  std::cout << "TargettedGraphName : " << Tree.GraphName << "\n";

  adg::Concept Main_concept = adg::Concept("Company");
  adg::Concept Secondary_Concept = adg::Concept("Private Company");
  std::vector<adg::Concept> Concept_vector{Main_concept, Secondary_Concept, adg::Concept("Government Company")};
  
  
  for (auto& c : Concept_vector) {
      Tree.ConceptsList.push_back(&c);
  }

  //Main_concept.AddSubConcept(&Secondary_Concept);
  Tree.ConceptsList[0]->AddSubConcept(Tree.ConceptsList[1]);


  std::cout << Main_concept.Type << std::endl;
  std::cout << Tree.ConceptsList[1]->Type << std::endl;

}


