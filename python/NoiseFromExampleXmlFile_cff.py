import FWCore.ParameterSet.Config as cms

from OnlineDB.SiStripConfigDb.SiStripConfigDb_cfi import *
NoiseFromConfigDb = cms.ESSource("SiStripNoiseBuilderFromDb")

SiStripConfigDb.UsingDb = False
SiStripConfigDb.InputModuleXml = '/afs/cern.ch/cms/cmt/onlinedev/data/module.xml'
SiStripConfigDb.InputDcuInfoXml = ''
SiStripConfigDb.InputFedXml = ['/afs/cern.ch/cms/cmt/onlinedev/data/fed9.xml', '/afs/cern.ch/cms/cmt/onlinedev/data/fed15.xml']
