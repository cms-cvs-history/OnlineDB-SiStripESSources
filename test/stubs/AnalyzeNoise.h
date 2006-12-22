// Last commit: $Id: $
// Latest tag:  $Name:  $
// Location:    $Source: $

#ifndef OnlineDB_SiStripESSources_test_AnalyzeNoise_H
#define OnlineDB_SiStripESSources_test_AnalyzeNoise_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

/**
   @class AnalyzeNoise 
   @brief Simple class that analyzes Digis produced by RawToDigi unpacker
*/
class AnalyzeNoise : public edm::EDAnalyzer {

 public:
  
  AnalyzeNoise( const edm::ParameterSet& ) {;}
  ~AnalyzeNoise() {;}
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& ) {;}
  void endJob() {;}
  
};

#endif // OnlineDB_SiStripESSources_test_AnalyzeNoise_H

