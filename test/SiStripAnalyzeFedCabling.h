#ifndef OnlineDB_SiStripESSources_test_SiStripAnalyzeFedCabling_H
#define OnlineDB_SiStripESSources_test_SiStripAnalyzeFedCabling_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include <string>

/**
   @class SiStripAnalyzeFedCabling 
   @brief Simple class that analyzes Digis produced by RawToDigi unpacker
*/
class SiStripAnalyzeFedCabling : public edm::EDAnalyzer {

 public:
  
  SiStripAnalyzeFedCabling( const edm::ParameterSet& );
  ~SiStripAnalyzeFedCabling();
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& );
  void endJob();
  
};

#endif // OnlineDB_SiStripESSources_test_SiStripAnalyzeFedCabling_H

