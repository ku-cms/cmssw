import FWCore.ParameterSet.Config as cms

jetsAK4GenParticlesMatch = cms.EDFilter("MCTruthDeltaRMatcher",
     src = cms.InputTag("jetsAK4"),
     distMin = cms.double(0.15),
     matchPDGId = cms.vint32(1,2,3,4,5,6,24),
     matched = cms.InputTag("genParticleCandidates")
)
