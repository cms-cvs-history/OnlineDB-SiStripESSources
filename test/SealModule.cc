#include "FWCore/Framework/interface/MakerMacros.h"
#include "PluginManager/ModuleDef.h"
DEFINE_SEAL_MODULE();

#include "OnlineDB/SiStripESSources/test/SiStripPopulateConfigDb.h"
DEFINE_ANOTHER_FWK_MODULE(SiStripPopulateConfigDb)

#include "OnlineDB/SiStripESSources/test/SiStripAnalyzeFedCabling.h"
DEFINE_ANOTHER_FWK_MODULE(SiStripAnalyzeFedCabling)
