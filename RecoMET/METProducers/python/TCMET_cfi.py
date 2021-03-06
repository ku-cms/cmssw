import FWCore.ParameterSet.Config as cms

##____________________________________________________________________________||
tcMet = cms.EDProducer(
    "TCMETProducer",
    alias = cms.string('tcMet'),
    electronVetoCone = cms.bool(True),
    electronInputTag  = cms.InputTag("gedGsfElectrons"),
    muonInputTag      = cms.InputTag("muons"),
    trackInputTag     = cms.InputTag("generalTracks"),
    metInputTag       = cms.InputTag("caloMet"),
    beamSpotInputTag  = cms.InputTag("offlineBeamSpot"),
    vertexInputTag    = cms.InputTag("offlinePrimaryVertices"),
    muonDepValueMap   = cms.InputTag("muonMETValueMapProducer"  , "muCorrData"),
    tcmetDepValueMap  = cms.InputTag("muonTCMETValueMapProducer", "muCorrData"),
    pt_min  = cms.double(1.0),
    pt_max  = cms.double(100.),
    eta_max = cms.double(2.65),
    chi2_max = cms.double(5),
    nhits_min = cms.double(6),
    ptErr_max = cms.double(0.2),
    track_quality = cms.vint32(2),
    track_algos = cms.vint32(),
    isCosmics = cms.bool(False),
    rf_type = cms.int32(1),
    correctShowerTracks = cms.bool(False),
    usePvtxd0 = cms.bool(False),
    nMinOuterHits = cms.int32(2),
    usedeltaRRejection = cms.bool(False),
    deltaRShower = cms.double(0.01),
    checkTrackPropagation = cms.bool(False),
    radius  = cms.double(130.),
    zdist  = cms.double(314.),
    corner = cms.double(1.479),
    d0cuta = cms.double(0.015),
    d0cutb = cms.double(0.5),
    maxd0cut = cms.double(0.3),
    chi2_tight_max = cms.double(5.0),
    nhits_tight_min = cms.double(9),
    ptErr_tight_max = cms.double(0.2),
    eVetoDeltaR = cms.double(0.015),
    eVetoDeltaPhi = cms.double(100.0),
    eVetoDeltaCotTheta = cms.double(100.0),
    eVetoMinElectronPt = cms.double(10.0),
    hOverECut = cms.double(0.1),
    maxTrackAlgo = cms.int32(8),
    nLayers = cms.int32(0),
    nLayersTight = cms.int32(0),
    vertexNdof = cms.int32(4),
    vertexZ = cms.double(15.),
    vertexRho = cms.double(2.),
    vertexMaxDZ = cms.double(0.2),
    maxpt_eta25 = cms.double(0.),
    maxpt_eta20 = cms.double(100.),
    vetoDuplicates = cms.bool(False),
    dupMinPt = cms.double(0.),
    dupDPhi = cms.double(0.03),
    dupDCotTh = cms.double(0.0006),
    PFClustersECAL = cms.InputTag("particleFlowClusterECAL"),
    PFClustersHCAL = cms.InputTag("particleFlowClusterHCAL"),
    PFClustersHF = cms.InputTag("particleFlowClusterHF"),
    usePFClusters = cms.bool(False)
    )

##____________________________________________________________________________||
tcMetWithPFclusters = tcMet.clone()
tcMetWithPFclusters.alias = cms.string('tcMetWithPFclusters')
tcMetWithPFclusters.usePFClusters = cms.bool(True)

##____________________________________________________________________________||
