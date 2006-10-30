#ifndef OnlineDB_SiStripESSources_test_AnalyzeFedCabling_H
#define OnlineDB_SiStripESSources_test_AnalyzeFedCabling_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

/**
   @class AnalyzeFedCabling 
   @brief Simple class that analyzes Digis produced by RawToDigi unpacker
*/
class AnalyzeFedCabling : public edm::EDAnalyzer {

 public:
  
  AnalyzeFedCabling( const edm::ParameterSet& ) {;}
  ~AnalyzeFedCabling() {;}
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& ) {;}
  void endJob() {;}
  
};

#endif // OnlineDB_SiStripESSources_test_AnalyzeFedCabling_H

