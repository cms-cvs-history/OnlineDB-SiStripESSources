// Last commit: $Id: $
// Latest tag:  $Name: $
// Location:    $Source: $

#ifndef OnlineDB_SiStripESSources_test_SiStripFedCablingBuilderToCondDb_H
#define OnlineDB_SiStripESSources_test_SiStripFedCablingBuilderToCondDb_H

#include "OnlineDB/SiStripESSources/interface/SiStripFedCablingBuilderFromDb.h"
#include "OnlineDB/SiStripConfigDb/interface/SiStripConfigDb.h"
#include "boost/cstdint.hpp"
#include <string>

class SiStripFedCablingBuilderToCondDb : public SiStripFedCablingBuilderFromDb {
  
 public:

  SiStripFedCablingBuilderToCondDb( const edm::ParameterSet& );
  ~SiStripFedCablingBuilderToCondDb(); 
  
 protected:
  
  /** Virtual method that is called by makeFedCabling() to allow FED
      cabling to be written to the conds DB (local or otherwise). */
  void writeFedCablingToCondDb( const SiStripFedCabling& );

 private:

  std::string user_;
  std::string passwd_;
  
};

#endif // OnlineDB_SiStripESSources_test_SiStripFedCablingBuilderToCondDb_H


