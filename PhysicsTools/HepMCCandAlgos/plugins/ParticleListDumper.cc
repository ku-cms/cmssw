#include <memory>
#include <string>
#include <iostream>
#include <sstream>

#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "SimGeneral/HepPDTRecord/interface/ParticleDataTable.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Common/interface/Ref.h"

#include <TTree.h>

/**
  \class   ParticleListDumper ParticleListDumper.h "PhysicsTools/HepMCCandAlgos/plugins/ParticleListDumper.h"

  \brief   Module to dump the particle listing as provided by common event generators into a ROOT file

Caveats:
Status 3 particles can have daughters both with status 2 and 3. In pythia this is not
the same mother-daughter. The relations are correct but special care has to be taken
when looking at mother-daughter relation which involve status 2 and 3 particles.
*/


using namespace std;
using namespace reco;
using namespace edm;


const UInt_t nMaxParts = 10000;

class ParticleInfo{
  public:
    void RegisterTree(TTree *tree, std::string name="") {
      if(name!="") name += ".";
      tree -> Branch ((name+"nPart").c_str() ,&nPart ,(name+"nPart/I").c_str()) ; 
      tree -> Branch ((name+"idx").c_str()   ,&idx   ,(name+"idx["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"pdgid").c_str() ,&pdgid ,(name+"pdgid["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"name").c_str()  ,&name  ,(name+"name["+name+"nPart]/C").c_str()) ; 
      tree -> Branch ((name+"stat").c_str()  ,&stat  ,(name+"stat["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"iMo1").c_str()  ,&iMo1  ,(name+"iMo1["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"iMo2").c_str()  ,&iMo2  ,(name+"iMo2["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"iDa1").c_str()  ,&iDa1  ,(name+"iDa1["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"iDa2").c_str()  ,&iDa2  ,(name+"iDa2["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"nMo").c_str()   ,&nMo   ,(name+"nMo["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"nDa").c_str()   ,&nDa   ,(name+"nDa["+name+"nPart]/I").c_str()) ; 
      tree -> Branch ((name+"pt").c_str()    ,&pt    ,(name+"pt["+name+"nPart]/F").c_str()) ; 
      tree -> Branch ((name+"eta").c_str()   ,&eta   ,(name+"eta["+name+"nPart]/F").c_str()) ; 
      tree -> Branch ((name+"phi").c_str()   ,&phi   ,(name+"phi["+name+"nPart]/F").c_str()) ; 
      tree -> Branch ((name+"px").c_str()    ,&px    ,(name+"px["+name+"nPart]/F").c_str()) ; 
      tree -> Branch ((name+"py").c_str()    ,&py    ,(name+"py["+name+"nPart]/F").c_str()) ; 
      tree -> Branch ((name+"pz").c_str()    ,&pz    ,(name+"pz["+name+"nPart]/F").c_str()) ; 
      tree -> Branch ((name+"e").c_str()     ,&e     ,(name+"e["+name+"nPart]/F").c_str()) ; 
      tree -> Branch ((name+"mass").c_str()  ,&mass  ,(name+"mass["+name+"nPart]/F").c_str()) ; 
    }

    int    nPart            ; 
    int    idx  [nMaxParts] ;
    int    pdgid[nMaxParts] ; 
    string name [nMaxParts] ; 
    int    stat [nMaxParts] ;
    int    iMo1 [nMaxParts] ;
    int    iMo2 [nMaxParts] ;
    int    iDa1 [nMaxParts] ;
    int    iDa2 [nMaxParts] ;
    int    nMo  [nMaxParts] ;
    int    nDa  [nMaxParts] ; 
    float  pt   [nMaxParts] ; 
    float  eta  [nMaxParts] ; 
    float  phi  [nMaxParts] ; 
    float  px   [nMaxParts] ; 
    float  py   [nMaxParts] ; 
    float  pz   [nMaxParts] ; 
    float  e    [nMaxParts] ; 
    float  mass [nMaxParts] ; 

};

class ParticleListDumper : public edm::EDAnalyzer {
  public:
    explicit ParticleListDumper(const edm::ParameterSet & );
    ~ParticleListDumper() {};
    void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) override;

  private:
    std::string getParticleName( int id ) const;

    edm::InputTag src_;
    edm::EDGetTokenT<reco::CandidateView> srcToken_;
    edm::ESHandle<ParticleDataTable> pdt_;
    int maxEventsToPrint_; // Must be signed, because -1 is used for no limit
    unsigned int nEventAnalyzed_;
    bool printOnlyHardInteraction_;
    bool printVertex_;
    ParticleInfo Parts_; 
    TTree* tree_; 
    edm::Service<TFileService> fs;
};

ParticleListDumper::ParticleListDumper(const edm::ParameterSet & pset) :
  src_(pset.getParameter<InputTag>("src")),
  srcToken_(consumes<reco::CandidateView>(src_)),
  maxEventsToPrint_ (pset.getUntrackedParameter<int>("maxEventsToPrint",1)),
  nEventAnalyzed_(0),
  printOnlyHardInteraction_(pset.getUntrackedParameter<bool>("printOnlyHardInteraction", false)),
  printVertex_(pset.getUntrackedParameter<bool>("printVertex", false)) 
  { 
  tree_ = fs->make<TTree>("ttree", "ttree");
  Parts_.RegisterTree(tree_) ; 
  }

std::string ParticleListDumper::getParticleName(int id) const
{
  const ParticleData * pd = pdt_->particle( id );
  if (!pd) {
    std::ostringstream ss;
    ss << "P" << id;
    return ss.str();
  } else
    return pd->name();
}

void ParticleListDumper::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  Handle<reco::CandidateView> particles;
  iEvent.getByToken(srcToken_, particles );
  iSetup.getData( pdt_ );

  if(maxEventsToPrint_ < 0 || nEventAnalyzed_ < static_cast<unsigned int>(maxEventsToPrint_)) {
    Parts_.nPart = -1 ; 
    vector<const reco::Candidate *> cands;
    vector<const Candidate *>::const_iterator found = cands.begin();
    for(CandidateView::const_iterator p = particles->begin();
        p != particles->end(); ++ p) {
      cands.push_back(&*p);
    }

    for(CandidateView::const_iterator p  = particles->begin();
        p != particles->end();
        p ++) {
      if (printOnlyHardInteraction_ && p->status() != 3) continue;

      ++Parts_.nPart ; 

      // Particle Name
      int id = p->pdgId();
      string particleName = getParticleName(id);

      // Particle Index
      Parts_.idx[Parts_.nPart] =  p - particles->begin();

      // Partarts_.nParticles Mothers and Daighters
      Parts_.nMo[Parts_.nPart] = p->numberOfMothers();
      Parts_.nDa[Parts_.nPart] = p->numberOfDaughters();
      Parts_.iMo1[Parts_.nPart] = -1;
      Parts_.iMo2[Parts_.nPart] = -1;
      Parts_.iDa1[Parts_.nPart] = -1;
      Parts_.iDa2[Parts_.nPart] = -1;

      found = find(cands.begin(), cands.end(), p->mother(0));
      if(found != cands.end()) Parts_.iMo1[Parts_.nPart] = found - cands.begin() ;

      found = find(cands.begin(), cands.end(), p->mother(Parts_.nMo[Parts_.nPart]-1));
      if(found != cands.end()) Parts_.iMo2[Parts_.nPart] = found - cands.begin() ;

      found = find(cands.begin(), cands.end(), p->daughter(0));
      if(found != cands.end()) Parts_.iDa1[Parts_.nPart] = found - cands.begin() ;

      found = find(cands.begin(), cands.end(), p->daughter(Parts_.nDa[Parts_.nPart]-1));
      if(found != cands.end()) Parts_.iDa2[Parts_.nPart] = found - cands.begin() ;

      Parts_.pdgid[Parts_.nPart] = p->pdgId() ; 
      Parts_.name[Parts_.nPart] = particleName.c_str() ; 
      Parts_.stat[Parts_.nPart] = p->status() ; 
      Parts_.pt[Parts_.nPart] = p->pt() ; 
      Parts_.eta[Parts_.nPart] = p->eta() ; 
      Parts_.phi[Parts_.nPart] = p->phi() ; 
      Parts_.px[Parts_.nPart] = p->px() ; 
      Parts_.py[Parts_.nPart] = p->py() ; 
      Parts_.pz[Parts_.nPart] = p->pz() ; 
      Parts_.e[Parts_.nPart] = p->energy() ; 
      Parts_.mass[Parts_.nPart] = p->mass() ; 
    }
    nEventAnalyzed_++;
    tree_->Fill() ; 
  }
}

DEFINE_FWK_MODULE(ParticleListDumper);

