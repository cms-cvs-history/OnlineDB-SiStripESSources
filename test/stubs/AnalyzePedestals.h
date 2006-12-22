// Last commit: $Id: $
// Latest tag:  $Name:  $
// Location:    $Source: $

#ifndef OnlineDB_SiStripESSources_test_AnalyzePedestals_H
#define OnlineDB_SiStripESSources_test_AnalyzePedestals_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

/**
   @class AnalyzePedestals 
   @brief Simple class that analyzes Digis produced by RawToDigi unpacker
*/
class AnalyzePedestals : public edm::EDAnalyzer {

 public:
  
  AnalyzePedestals( const edm::ParameterSet& ) {;}
  ~AnalyzePedestals() {;}
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& ) {;}
  void endJob() {;}
  
};

#endif // OnlineDB_SiStripESSources_test_AnalyzePedestals_H

