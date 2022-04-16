#include "adg.hpp"

namespace adg {

  /*
   * @brief 	Adds a Sub Concept to the graph
   *
   * @details Adds the Concept to the ChildConcepts vector 
   *          and changes the node type accordingly
   * @param[in] ChildConcept Pointer to Concept type
   */
  void Concept::AddSubConcept(Concept *ChildConcept) {
    
    this->ChildConcepts.push_back(ChildConcept);
  
    // Changing the NodeIndicatorTypes accordingly
    if (this->Type == adg::NodeTypeIndicator::None)
      this->Type = adg::NodeTypeIndicator::RootNode;
    else if (this->Type == adg::NodeTypeIndicator::LeafNode)
      this->Type = adg::NodeTypeIndicator::ParentNode;
  
    if(ChildConcept->Type == adg::NodeTypeIndicator::None)
      ChildConcept->Type = adg::NodeTypeIndicator::LeafNode;
    else if (ChildConcept->Type == adg::NodeTypeIndicator::RootNode)
      ChildConcept->Type = adg::NodeTypeIndicator::ParentNode;

    this->ChildConcepts.push_back(ChildConcept);
    
  }
  
  
  void Concept::AddSuperConcept(Concept *ParentConcept) {
    this->ChildConcepts.push_back(ParentConcept);
  
    // Changing the NodeIndicatorTypes accordingly
    if (this->Type == adg::NodeTypeIndicator::None)
      this->Type = adg::NodeTypeIndicator::LeafNode;
    else if (this->Type == adg::NodeTypeIndicator::RootNode)
      this->Type = adg::NodeTypeIndicator::ParentNode;
  
    if(ParentConcept->Type == adg::NodeTypeIndicator::None)
      ParentConcept->Type = adg::NodeTypeIndicator::RootNode;
    else if (ParentConcept->Type == adg::NodeTypeIndicator::LeafNode)
      ParentConcept->Type = adg::NodeTypeIndicator::ParentNode;

    ParentConcept->ChildConcepts.push_back(this);
  };

  std::vector<Concept*> returnBaseConcepts (TargettedGraph T) {
    std::vector<Concept*> BaseConcepts {};
    for (Concept* c: T.ConceptsList) {
      if (c->Type == adg::NodeTypeIndicator::RootNode)
        BaseConcepts.push_back(c);
    }
    return BaseConcepts;
  }

  std::vector<Concept*> returnLastConcepts (TargettedGraph T) {
    std::vector<Concept*> LeafConcepts {};
    for (Concept* c: T.ConceptsList) {
      if (c->Type == adg::NodeTypeIndicator::LeafNode)
        LeafConcepts.push_back(c);
    }
    
    return LeafConcepts; 
  }

  void emptyConcept(std::vector<Concept*> &ConceptQueue) {
    ConceptQueue.empty(); 
  }
  
  void popConcept(std::vector<Concept*> &ConceptQueue) {
    ConceptQueue.pop_back(); }

  void pushConcept (std::vector<Concept*> &ConceptQueue, Concept NewConcept) {
    ConceptQueue.push_back(&NewConcept); }

}
