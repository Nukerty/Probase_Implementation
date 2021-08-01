#pragma once

#include <vector>
#include <string>

namespace adg {

  /*inline namespace ID_keeper{
    std::vector<unsigned int> TGraphID {0};
    std::vector<unsigned int> ConceptIDNumber {0};
  };*/


  enum NodeTypeIndicator : int {RootNode, ParentNode, LeafNode, None};
  
  /* 
   * Concepts are just base nodes which are the fundamental structure of the 
   * whole damn thing.
   */
  class Concept
  {
    /*private :
      unsigned int ConceptID;*/
    public:
    std::string ConceptTitle;
    std::vector<Concept*> ChildConcepts;
    NodeTypeIndicator Type;
 

    // Concept constructor with Title 
    Concept(std::string Title) {
      Concept::ConceptTitle = Title;
      Concept::Type = NodeTypeIndicator::None;
    };

    ~Concept() {
    }


    // Adding a subconcept to the base Concept
    void AddSubConcept(Concept *ChildConcept);

    // Adding a superconcept to the Concept
    void AddSuperConcept(Concept *ParentConcept);

  };
  
  /*
   * Targetted Graphs containing all concepts which constitutes a graph
   */
  class TargettedGraph
  {
    /*private :
      unsigned int TGraphID;*/
    public:
    std::string GraphName, GraphDescription;
    std::vector<Concept*> ConceptsList;

    
    TargettedGraph (std::string GraphName) {
      TargettedGraph::GraphName = GraphName;
      /*ID_keeper::TGraphID.push_back( ID_keeper::TGraphID.back() + 1 );
      TargettedGraph::TGraphID = ID_keeper::TGraphID.back();*/
    };

    ~TargettedGraph() {}

    /*unsigned int ReturnID () { return TGraphID; }*/

  };


  /*
   * Return the Concept lists with no Parent Nodes
   */
  std::vector<Concept*> returnBaseConcepts (TargettedGraph T);

  /*
   * Return the Concept lists with no Child Nodes
   */
  std::vector<Concept*> returnLastConcepts (TargettedGraph T);

  /*
   * Clear out the TargettedGraph
   */
  void emptyConcept (std::vector<Concept> &ConceptQueue);

  /*
   * Extract out the last inserted Concept in a Concept vector
   */
  void popConcept (std::vector<Concept> &ConceptQueue);

  /*
   * Push in a Concept into the ConceptQueue
   */
  void pushConcept (std::vector<Concept> &ConceptQueue, Concept NewConcept);

}
