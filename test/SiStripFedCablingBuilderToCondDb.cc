// Last commit: $Id: $
// Latest tag:  $Name: $
// Location:    $Source: $
#include "OnlineDB/SiStripESSources/test/SiStripFedCablingBuilderToCondDb.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CondCore/DBOutputService/interface/PoolDBOutputService.h"
#include "CondFormats/SiStripObjects/interface/SiStripFedCabling.h"
#include <sstream>
#include <iomanip>

using namespace std;
using namespace cms;

// -----------------------------------------------------------------------------
/** */
SiStripFedCablingBuilderToCondDb::SiStripFedCablingBuilderToCondDb( const edm::ParameterSet& pset ) 
  : SiStripFedCablingBuilderFromDb( pset ),
    user_( "CORAL_AUTH_USER=" + pset.getUntrackedParameter<string>("User","user") ),
    passwd_( "CORAL_AUTH_PASSWORD=" + pset.getUntrackedParameter<string>("Passwd","passwd") )
{
  edm::LogVerbatim(logCategory_) << "[" << __PRETTY_FUNCTION__ << "] Constructing object...";
  
  ::putenv( const_cast<char*>(user_.c_str()) );
  ::putenv( const_cast<char*>(passwd_.c_str()) );
  
}

// -----------------------------------------------------------------------------
/** */
SiStripFedCablingBuilderToCondDb::~SiStripFedCablingBuilderToCondDb() {
  edm::LogVerbatim(logCategory_) << "[SiStripFedCablingBuilderToCondDb::~SiStripFedCablingBuilderToCondDb]"
				  << " Destructing object...";
}

// -----------------------------------------------------------------------------
/** */
void SiStripFedCablingBuilderToCondDb::writeFedCablingToCondDb( const SiStripFedCabling& fed_cabling ) {
  static const string method = "SiStripFedCablingBuilderToCondDb::writeFedCablingToCondDb";
  edm::LogVerbatim(logCategory_) << "["<<method<<"]";

  edm::Service<cond::service::PoolDBOutputService> db;
  if ( db.isAvailable() ) {
    try {
      edm::LogVerbatim(logCategory_) << "current time " << db->currentTime();
      db->newValidityForNewPayload<SiStripFedCabling>( const_cast<SiStripFedCabling*>(&fed_cabling), 
						       db->currentTime(), 
						       db->callbackToken("SiStripFedCabling") );
    } catch ( const cond::Exception& e ) {
      stringstream ss;
      ss << "Caught cond::Exception in method " << __PRETTY_FUNCTION__
	 << " and file:line " << __FILE__ << ":" << __LINE__
	 << " with message: \n" 
	 << e.what();
      edm::LogError(logCategory_) << ss.str();
      throw cms::Exception(logCategory_) << ss.str() << "\n";
    } catch ( const std::exception& e ) {
      stringstream ss;
      ss << "Caught std::Exception in method " << __PRETTY_FUNCTION__
	 << " and file+line " << __FILE__ << "+" << __LINE__
	 << " with message: \n" 
	 << e.what();
      edm::LogError(logCategory_) << ss.str();
      throw cms::Exception(logCategory_) << ss.str() << "\n";
    } catch (...) {
      stringstream ss;
      ss << "Caught unknown exception in method " << __PRETTY_FUNCTION__
	 << " and file+line " << __FILE__ << "+" << __LINE__;
      edm::LogError(logCategory_) << ss.str();
      throw cms::Exception(logCategory_) << ss.str() << "\n";
    }
  } else {
      stringstream ss;
      ss << "cond::service::PoolDBOutputService is unavailable!"
	 << " cms::Exception thrown in method " << __PRETTY_FUNCTION__
	 << " and file+line " << __FILE__ << "+" << __LINE__;
      edm::LogError(logCategory_) << ss.str();
      throw cms::Exception(logCategory_) << ss.str() << "\n";
  }
}


