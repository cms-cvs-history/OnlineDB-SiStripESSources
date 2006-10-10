#include "OnlineDB/SiStripESSources/test/stubs/TestFedCablingBuilder.h"
//
#include "FWCore/MessageLogger/interface/MessageLogger.h"
//
#include "CondFormats/SiStripObjects/interface/SiStripFedCabling.h"
#include "DataFormats/SiStripCommon/interface/SiStripConstants.h"
#include "OnlineDB/SiStripConfigDb/interface/SiStripConfigDb.h"
#include "OnlineDB/SiStripESSources/interface/SiStripFedCablingBuilderFromDb.h"
//
#include <iostream>
#include <sstream>

using namespace std;
using namespace sistrip;

// -----------------------------------------------------------------------------
// 
TestFedCablingBuilder::TestFedCablingBuilder( const edm::ParameterSet& pset ) 
  : db_(0),
    source_( pset.getUntrackedParameter<string>( "Source", "CONNECTIONS" ) )
{
  LogTrace(mlCabling_) << __func__ << " Constructing object...";
  
  if ( pset.getUntrackedParameter<bool>( "UsingDb", true ) ) {
    db_ = new SiStripConfigDb( pset.getUntrackedParameter<string>("ConfDb",""),
			       pset.getUntrackedParameter<string>("Partition",""),
			       pset.getUntrackedParameter<unsigned int>("MajorVersion",0),
			       pset.getUntrackedParameter<unsigned int>("MinorVersion",0) );
    if ( db_ ) { db_->openDbConnection(); }
  } else {
    edm::LogError(mlCabling_) << " Cannot use database! 'UsingDb' is false!";
  }
  
  LogTrace(mlCabling_) << " 'SOURCE' configurable set to: " << source_;
  
}

// -----------------------------------------------------------------------------
// 
TestFedCablingBuilder::~TestFedCablingBuilder() {
  if ( db_ ) { 
    db_->closeDbConnection();
    delete db_;
  } 
  LogTrace(mlCabling_) << __func__ << " Destructing object...";
}

// -----------------------------------------------------------------------------
// 
void TestFedCablingBuilder::beginJob( const edm::EventSetup& setup ) {
  
  SiStripFecCabling fec_cabling;
  SiStripConfigDb::DcuDetIdMap dcu_detid_map;
  
  // Build FED cabling
  if ( source_ == "CONNECTIONS" ) { 
    SiStripFedCablingBuilderFromDb::buildFecCablingFromFedConnections( db_, 
								       fec_cabling, 
								       dcu_detid_map );
  } else if ( source_ == "DEVICES" ) {
    SiStripFedCablingBuilderFromDb::buildFecCablingFromDevices( db_, 
								fec_cabling, 
								dcu_detid_map );
  } else if ( source_ == "DETID" ) { 
    SiStripFedCablingBuilderFromDb::buildFecCablingFromDetIds( db_, 
							       fec_cabling, 
							       dcu_detid_map );
  } else if ( source_ == "UNDEFINED" ) { 
    SiStripFedCablingBuilderFromDb::buildFecCabling( db_, 
						     fec_cabling, 
						     dcu_detid_map );
  } else { 
    edm::LogError(mlCabling_)
      << "Unable to build FEC cabling!"
      << " Unexpected value for 'SOURCE' configurable: " << source_ << endl;
    return;
  }

  // Build FED cabling object
  SiStripFedCabling fed_cabling;
  SiStripFedCablingBuilderFromDb::getFedCabling( fec_cabling, fed_cabling );

  // Some debug
  const NumberOfDevices& devs = fec_cabling.countDevices();
  LogTrace(mlCabling_)
    << "Built SiStripFecCabling object with following devices:" << endl
    << endl << devs;
  
//   int cntr = 0;
//   vector<uint16_t>::const_iterator ifed = fed_cabling.feds().begin();
//   for ( ; ifed != fed_cabling.feds().end(); ifed++ ) {
//     const vector<FedChannelConnection>& conns = fed_cabling.connections( *ifed ); 
//     vector<FedChannelConnection>::const_iterator ichan = conns.begin();
//     for ( ; ichan != conns.end(); ichan++ ) { 
//       if ( ichan->fedId() ) {
// 	LogTrace(mlCabling_) << "FED Channel connection: " << cntr << endl << *ichan << endl;
// 	cntr++;
//       }
//     } 
//   } 
  
}

