#ifndef ANALYSISDATAFORMATS_BOOSTEDOBJECTS_JET_HH
#define ANALYSISDATAFORMATS_BOOSTEDOBJECTS_JET_HH

#include "AnalysisDataFormats/BoostedObjects/interface/ResolvedVjj.h"

#include<iostream>

/*\ 
 * Simple Jet class to be used with B2G EDMNtuples
 * https://github.com/cmsb2g/B2GAnaFW
 */

namespace vlq{
  class Jet ;
  typedef std::vector<vlq::Jet> JetCollection ; 
  class Jet : public vlq::Candidate {
    friend class vlq::ResolvedVjj ; 
    public:
      Jet () : index_(-1), partonFlavour_(-1), hadronFlavour_(-1), csvDiscrimiator_(-1000), 
      isbtagged_(0), istoptagged_(0), ishtagged_(0), iswtagged_(0) {}
      Jet (const vlq::Jet& jet) :
        vlq::Candidate(jet),
        index_(jet.getIndex()), 
        partonFlavour_(jet.getPartonFlavour()),
        hadronFlavour_(jet.getHadronFlavour()), 
        csvDiscrimiator_(jet.getCSV()),
        tau1_(jet.getTau1()),
        tau2_(jet.getTau2()),
        tau3_(jet.getTau3()),
        filteredMass_(jet.getFilteredMass()),
        trimmedMass_(jet.getTrimmedMass()),
        prunedMass_(jet.getPrunedMass()),
        softDropMass_(jet.getSoftDropMass()),
        isbtagged_(jet.getIsbtagged()),
        istoptagged_(jet.getIstoptagged()),
        ishtagged_(jet.getIshtagged()),
        iswtagged_(jet.getIswtagged()) 
    { } 
      ~Jet () {}

      int    getIndex () const { return index_ ; } 
      int    getPartonFlavour () const { return partonFlavour_ ; } 
      int    getHadronFlavour () const { return hadronFlavour_ ; } 
      double getCSV () const { return csvDiscrimiator_ ; }
      double getTau1         () const { return tau1_          ; }
      double getTau2         () const { return tau2_          ; }
      double getTau3         () const { return tau3_          ; }
      double getFilteredMass () const { return filteredMass_  ; }
      double getTrimmedMass () const { return  trimmedMass_ ; }
      double getPrunedMass () const { return prunedMass_ ; }
      double getSoftDropMass () const { return softDropMass_ ; }
      bool   getIsbtagged () const { return isbtagged_ ; } 
      bool   getIstoptagged () const { return istoptagged_ ; }
      bool   getIshtagged () const { return ishtagged_ ; }
      bool   getIswtagged () const { return iswtagged_ ; } 

      void setIndex( const int& index) {index_ = index ; } 
      void setPartonFlavour( const int& partonflavour) { partonFlavour_ = partonflavour ; } 
      void setHadronFlavour( const int& hadronflavour) { hadronFlavour_ = hadronflavour ; } 
      void setCSV( const double& csv) {csvDiscrimiator_ = csv ; } 
      void setTau1         ( const double tau1 ) { tau1_ = tau1 ; }
      void setTau2         ( const double tau2 ) { tau2_ = tau2 ; }
      void setTau3         ( const double tau3 ) { tau3_ = tau3 ; }
      void setFilteredMass ( const double mass ) { filteredMass_ = mass ; }
      void setTrimmedMass ( const double mass ) { trimmedMass_ = mass ; }
      void setPrunedMass ( const double mass ) { prunedMass_ = mass ; }
      void setSoftDropMass ( const double mass ) { softDropMass_ = mass ; }
      void setIsbtagged( const bool& isbtagged) {isbtagged_ = isbtagged ; } 
      void setIstoptagged( const bool& istoptagged) {istoptagged_ = istoptagged ; }
      void setIshtagged( const bool& ishtagged) {ishtagged_ = ishtagged ; }
      void setIswtagged( const bool& iswtagged) {iswtagged_ = iswtagged ; } 

    protected:

      int index_ ; 
      int partonFlavour_ ;
      int hadronFlavour_ ; 
      double csvDiscrimiator_ ; 

      double tau1_ ;
      double tau2_ ;
      double tau3_ ;
      double filteredMass_ ;
      double trimmedMass_ ;
      double prunedMass_ ; 
      double softDropMass_ ; 

      bool isbtagged_ ; 
      bool istoptagged_ ;
      bool ishtagged_ ;
      bool iswtagged_ ; 
  }; 
}

#endif 
