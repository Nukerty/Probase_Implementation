// #define SPACY_HEADER_ONLY

#include <iostream>
#include <vector>

#include <ConceptGraphs/adg.hpp>
#include <ConceptGraphs/stream.hpp>
#include <ConceptGraphs/math.hpp>

#ifdef USE_MYMATH
#include <ConceptGraphs/adg.hpp>
#endif

#include <spacy/spacy>
#include <spacy/spacy.h>

namespace ss = syntactic_segmentation;

int main() {

  std::cout<<"Prog here"<<'\n';
  adg::NodeTypeIndicator num = adg::NodeTypeIndicator::LeafNode;
  std::cout << num << '\n';

  // run_tests();
  adg::TargettedGraph Tree("Test_concept");

  std::cout<<"TargettedGraphName : "<< Tree.GraphName
           // <<"\tTargettedGraph ID : "<<Tree.ReturnID()
           <<"\n";

  std::cout << "TargettedGraphName : " << Tree.GraphName << "\n";

  adg::Concept Main_concept = adg::Concept("Company");
  adg::Concept Secondary_Concept = adg::Concept("Private Company");
  std::vector<adg::Concept> Concept_vector{
    Main_concept, 
    Secondary_Concept, 
    adg::Concept("Government Company")};

  for (auto& c : Concept_vector) {
      Tree.ConceptsList.push_back(&c);
  }

  //Main_concept.AddSubConcept(&Secondary_Concept);
  Tree.ConceptsList[0]->AddSubConcept(Tree.ConceptsList[1]);

  std::cout << Main_concept.Type << std::endl;
  std::cout << Tree.ConceptsList[1]->Type << std::endl;

  std::vector<std::string> H {"help","happiness", "to find"};
  ss::print_strings(H);

  Spacy::Spacy spacy;
  auto nlp = spacy.load("en_core_web_trf");
  auto doc = nlp.parse("This is a sentence.");
  for (auto& token : doc.tokens())
      std::cout << token.text() << " [" << token.pos_() << "]\n";

}
