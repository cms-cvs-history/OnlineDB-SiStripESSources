#ifndef OnlineDB_SiStripESSources_test_FedCablingBuilderFromDb_H
#define OnlineDB_SiStripESSources_test_FedCablingBuilderFromDb_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <string>

class SiStripConfigDb;

/**
   @class test_FedCablingBuilderFromDb 
   @author R.Bainbridge
   @brief Simple class that tests FED cabling ESSource.
*/
class test_FedCablingBuilderFromDb : public edm::EDAnalyzer {

 public:
  
  test_FedCablingBuilderFromDb( const edm::ParameterSet& );
  ~test_FedCablingBuilderFromDb();
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& ) {;}
  void endJob() {;}

 private:

  SiStripConfigDb* db_;
  std::string source_;
  
};

#endif // OnlineDB_SiStripESSources_test_FedCablingBuilderFromDb_H

