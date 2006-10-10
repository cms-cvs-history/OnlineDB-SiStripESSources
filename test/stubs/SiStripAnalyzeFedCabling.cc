#include "OnlineDB/SiStripESSources/test/stubs/SiStripAnalyzeFedCabling.h"
//
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
//
#include "CondFormats/DataRecord/interface/SiStripFedCablingRcd.h"
#include "CondFormats/SiStripObjects/interface/SiStripFedCabling.h"
//
#include <iostream>
#include <sstream>

using namespace std;

// -----------------------------------------------------------------------------
// 
void SiStripAnalyzeFedCabling::beginJob( const edm::EventSetup& setup ) {
  edm::LogVerbatim("FedCabling") 
    << "[" << __PRETTY_FUNCTION__ << "]"
    << " Dumping all FED-FEC connections...";

  edm::ESHandle<SiStripFedCabling> fed_cabling;
  setup.get<SiStripFedCablingRcd>().get( fed_cabling ); 
  
  int cntr = 0;
  vector<uint16_t>::const_iterator ifed = fed_cabling->feds().begin();
  for ( ; ifed != fed_cabling->feds().end(); ifed++ ) {
    const vector<FedChannelConnection>& conns = fed_cabling->connections( *ifed ); 
    vector<FedChannelConnection>::const_iterator ichan = conns.begin();
    for ( ; ichan != conns.end(); ichan++ ) { 
      if ( ichan->fedId() ) {
	edm::LogVerbatim("FedCabling")
	  << "ChannelCounter=" << cntr << " " << *ichan << endl;
	cntr++;
      }
    } 
  } 
  
}

