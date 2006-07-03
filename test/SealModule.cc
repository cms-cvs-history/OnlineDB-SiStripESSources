#include "PluginManager/ModuleDef.h"
DEFINE_SEAL_MODULE();

#include "FWCore/Framework/interface/MakerMacros.h"
#include "OnlineDB/SiStripESSources/test/SiStripPopulateConfigDb.h"
DEFINE_ANOTHER_FWK_MODULE(SiStripPopulateConfigDb)
