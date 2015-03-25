#ifndef ANALYSISDATAFORMATS_BOOSTEDOBJECTS_GENPARTICLE_HH
#define ANALYSISDATAFORMATS_BOOSTEDOBJECTS_GENPARTICLE_HH

#include "AnalysisDataFormats/BoostedObjects/interface/Candidate.h"

namespace vlq {
  class GenParticle : public Candidate {
    public: 
      GenParticle () : charge_(-999999), pdgID_(-999999), momPdgID_(-999999), status_(-999999) {} 
      ~GenParticle () {} 

      int getCharge () const {return charge_ ; }
      int getPdgID_ () const { return pdgID_ ; }
      int getMomPdgID_ () const { return momPdgID_ ; }
      int getStatus_ () const { return status_ ; } 

      void setCharge ( const int charge ) {charge_ = charge ; }
      void setPdgID_ ( const int pdgID )  { pdgID_ = pdgID ; }
      void setMomPdgID_ ( const int momPdgID ) { momPdgID_ = momPdgID ; }
      void setStatus_ ( const int status ) { status_ = status ; } 

    protected:
      int charge_ ; 
      int pdgID_ ;
      int momPdgID_ ;
      int status_ ; 
  }; 
}
#endif
