// Last commit: $Id: test_FedCablingBuilder.h,v 1.3 2006/12/22 12:30:40 bainbrid Exp $
// Latest tag:  $Name:  $
// Location:    $Source: /cvs_server/repositories/CMSSW/CMSSW/OnlineDB/SiStripESSources/test/stubs/Attic/test_FedCablingBuilder.h,v $

#ifndef OnlineDB_SiStripESSources_test_FedCablingBuilder_H
#define OnlineDB_SiStripESSources_test_FedCablingBuilder_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

/**
   @class test_FedCablingBuilder 
   @brief Simple class that analyzes Digis produced by RawToDigi unpacker
*/
class test_FedCablingBuilder : public edm::EDAnalyzer {

 public:
  
  test_FedCablingBuilder( const edm::ParameterSet& ) {;}
  ~test_FedCablingBuilder() {;}
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& ) {;}
  void endJob() {;}
  
};

#endif // OnlineDB_SiStripESSources_test_FedCablingBuilder_H
