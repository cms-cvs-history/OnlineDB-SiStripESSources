#include "OnlineDB/SiStripESSources/test/SiStripAnalyzeFedCabling.h"
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
SiStripAnalyzeFedCabling::SiStripAnalyzeFedCabling( const edm::ParameterSet& pset ) 
{
  edm::LogVerbatim("FedCabling")
    << __PRETTY_FUNCTION__ << " Constructing object...";
}

// -----------------------------------------------------------------------------
//
SiStripAnalyzeFedCabling::~SiStripAnalyzeFedCabling() {
  edm::LogVerbatim("FedCabling")
    << __PRETTY_FUNCTION__ << " Destructing object...";
}

// -----------------------------------------------------------------------------
// 
void SiStripAnalyzeFedCabling::beginJob( const edm::EventSetup& setup ) {
  edm::LogVerbatim("FedCabling")
    << __PRETTY_FUNCTION__;

  // Retrieve FED cabling
  edm::ESHandle<SiStripFedCabling> fed_cabling;
  setup.get<SiStripFedCablingRcd>().get( fed_cabling ); 

  // Iterate through connections
  edm::LogVerbatim("FedCabling") << __PRETTY_FUNCTION__
				 << " Dumping all FED-FEC connections...";
  int cntr = 0;
  vector<uint16_t>::const_iterator ifed = fed_cabling->feds().begin();
  for ( ; ifed != fed_cabling->feds().end(); ifed++ ) {
    const vector<FedChannelConnection>& conns = fed_cabling->connections( *ifed ); 
    vector<FedChannelConnection>::const_iterator ichan = conns.begin();
    for ( ; ichan != conns.end(); ichan++ ) { 
      if ( ichan->fedId() ) {
	stringstream ss;
	ss << "#" << cntr << ", ";
	ichan->print(ss);
	edm::LogVerbatim("FedCabling") << ss.str();
	cntr++;
      }
    } 
  } 
  
}

// -----------------------------------------------------------------------------
// 
void SiStripAnalyzeFedCabling::endJob() {
  edm::LogVerbatim("FedCabling")
    << __PRETTY_FUNCTION__;
}

// -----------------------------------------------------------------------------
//
void SiStripAnalyzeFedCabling::analyze( const edm::Event& event, 
					const edm::EventSetup& setup ) {
  edm::LogVerbatim("FedCabling")
    << __PRETTY_FUNCTION__
    << " Analyzing run " << event.id().run() 
    << " and event " << event.id().event();


  // Retrieve FED cabling
  edm::ESHandle<SiStripFedCabling> fed_cabling;
  setup.get<SiStripFedCablingRcd>().get( fed_cabling ); 

  // Iterate through connections
  vector<uint16_t>::const_iterator ifed = fed_cabling->feds().begin();
  for ( ; ifed != fed_cabling->feds().end(); ifed++ ) {
    const vector<FedChannelConnection>& conns = fed_cabling->connections( *ifed ); 
    vector<FedChannelConnection>::const_iterator ichan = conns.begin();
    for ( ; ichan != conns.end(); ichan++ ) { 
      if ( ichan->fedId() ) {
	//@@ anything here?
      }
    } 
  } 

}
