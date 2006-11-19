#include "FWCore/Framework/interface/MakerMacros.h"
#include "PluginManager/ModuleDef.h"
DEFINE_SEAL_MODULE();

#include "OnlineDB/SiStripESSources/test/stubs/PopulateConfigDb.h"
DEFINE_ANOTHER_FWK_MODULE(PopulateConfigDb);

#include "OnlineDB/SiStripESSources/test/stubs/AnalyzeFedCabling.h"
DEFINE_ANOTHER_FWK_MODULE(AnalyzeFedCabling);

#include "OnlineDB/SiStripESSources/test/stubs/test_FedCablingBuilderFromDb.h"
DEFINE_ANOTHER_FWK_MODULE(test_FedCablingBuilderFromDb);

#include "OnlineDB/SiStripESSources/test/stubs/test_DatabaseService.h"
DEFINE_ANOTHER_FWK_MODULE(test_DatabaseService);