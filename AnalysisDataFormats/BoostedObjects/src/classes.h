#include "AnalysisDataFormats/BoostedObjects/interface/Jet.h"
#include "AnalysisDataFormats/BoostedObjects/interface/ResolvedVjj.h"
#include "DataFormats/Common/interface/Wrapper.h"

namespace AnalysisDataFormats_BoostedObjects {
  struct dictionary {
    vlq::Candidate vlqcandidate ;
    edm::Wrapper<vlq::Candidate> w_vlqCandidate ;
    std::vector<vlq::Candidate> v_vlqCandidate ;
    edm::Wrapper<std::vector<vlq::Candidate> > w_v_vlqCandidate ;

    vlq::Jet vlqjet ;
    edm::Wrapper<vlq::Jet> w_vlqJet ;
    std::vector<vlq::Jet> v_vlqJet ;
    edm::Wrapper<std::vector<vlq::Jet> > w_v_vlqJet ;

    vlq::ResolvedVjj vlqresolvedvjj ;
    edm::Wrapper<vlq::ResolvedVjj> w_vlqResolvedVjj ; 
    std::vector<vlq::ResolvedVjj> v_vlqResolvedVjj ;
    edm::Wrapper<std::vector<vlq::ResolvedVjj> > w_v_vlqResolvedVjj ;
  };
}
