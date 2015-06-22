#ifndef ANALYSISDATAFORMATS_BOOSTEDOBJECTS_MUON_HH
#define ANALYSISDATAFORMATS_BOOSTEDOBJECTS_MUON_HH

#include "AnalysisDataFormats/BoostedObjects/interface/Candidate.h"

/*\ 
 * Simple Muon class to be used with B2G EDMNtuples
 * https://github.com/cmsb2g/B2GAnaFW
 */

namespace vlq{
  class Muon ;
  typedef std::vector<vlq::Muon> MuonCollection ; 
  class Muon : public vlq::Candidate {
    public:
      Muon () : index_(-1) {} 
      Muon (const vlq::Muon& mu) :
        vlq::Candidate(mu),
        index_(mu.getIndex())  
    { } 
      ~Muon () {}

      int   getIndex                   () const { return index_                   ; }
      float getCharge                  () const { return Charge_                  ; }
      float getD0                      () const { return D0_                      ; }
      float getD0err                   () const { return D0err_                   ; }
      float getDxy                     () const { return Dxy_                     ; }
      float getDxyerr                  () const { return Dxyerr_                  ; }
      float getDz                      () const { return Dz_                      ; }
      float getDzerr                   () const { return Dzerr_                   ; }
      float getE                       () const { return E_                       ; }
      float getEta                     () const { return Eta_                     ; }
      float getGenMuonCharge           () const { return GenMuonCharge_           ; }
      float getGenMuonE                () const { return GenMuonE_                ; }
      float getGenMuonEta              () const { return GenMuonEta_              ; }
      float getGenMuonPhi              () const { return GenMuonPhi_              ; }
      float getGenMuonPt               () const { return GenMuonPt_               ; }
      float getGenMuonY                () const { return GenMuonY_                ; }
      float getGlbTrkNormChi2          () const { return GlbTrkNormChi2_          ; }
      float getInTrkNormChi2           () const { return InTrkNormChi2_           ; }
      float getIsGlobalMuon            () const { return IsGlobalMuon_            ; }
      float getIsLooseMuon             () const { return IsLooseMuon_             ; }
      float getIsPFMuon                () const { return IsPFMuon_                ; }
      float getIsSoftMuon              () const { return IsSoftMuon_              ; }
      float getIsTightMuon             () const { return IsTightMuon_             ; }
      float getIsTrackerMuon           () const { return IsTrackerMuon_           ; }
      float getIso04                   () const { return Iso04_                   ; }
      float getKey                     () const { return Key_                     ; }
      float getMass                    () const { return Mass_                    ; }
      float getNumberMatchedStations   () const { return NumberMatchedStations_   ; }
      float getNumberOfPixelLayers     () const { return NumberOfPixelLayers_     ; }
      float getNumberOfValidTrackerHits() const { return NumberOfValidTrackerHits_; } 
      float getNumberTrackerLayers     () const { return NumberTrackerLayers_     ; }
      float getNumberValidMuonHits     () const { return NumberValidMuonHits_     ; }
      float getNumberValidPixelHits    () const { return NumberValidPixelHits_    ; }
      float getPhi                     () const { return Phi_                     ; }
      float getPt                      () const { return Pt_                      ; }
      float getSumChargedHadronPt      () const { return SumChargedHadronPt_      ; }
      float getSumNeutralHadronPt      () const { return SumNeutralHadronPt_      ; }
      float getSumPUPt                 () const { return SumPUPt_                 ; }
      float getSumPhotonPt             () const { return SumPhotonPt_             ; }

      void setIndex                   (const int& index)                      {index_ = index                                       ; } 
      void getCharge                  (const float& Charge)                   { Charge_ = Charge                                    ; }
      void getD0                      (const float& D0)                       { D0_ = D0                                            ; }
      void getD0err                   (const float& D0err)                    { D0err_ = D0err                                      ; }
      void getDxy                     (const float& Dxy)                      { Dxy_ = Dxy                                          ; }
      void getDxyerr                  (const float& Dxyerr)                   { Dxyerr_ = Dxyerr                                    ; }
      void getDz                      (const float& Dz)                       { Dz_ = Dz                                            ; }
      void getDzerr                   (const float& Dzerr)                    { Dzerr_ = Dzerr                                      ; }
      void getE                       (const float& E)                        { E_ = E                                              ; }
      void getEta                     (const float& Eta)                      { Eta_ = Eta                                          ; }
      void getGenMuonCharge           (const float& GenMuonCharge)            { GenMuonCharge_ = GenMuonCharge                      ; }
      void getGenMuonE                (const float& GenMuonE)                 { GenMuonE_ = GenMuonE                                ; }
      void getGenMuonEta              (const float& GenMuonEta)               { GenMuonEta_ = GenMuonEta                            ; }
      void getGenMuonPhi              (const float& GenMuonPhi)               { GenMuonPhi_ = GenMuonPhi                            ; }
      void getGenMuonPt               (const float& GenMuonPt)                { GenMuonPt_ = GenMuonPt                              ; }
      void getGenMuonY                (const float& GenMuonY)                 { GenMuonY_ = GenMuonY                                ; }
      void getGlbTrkNormChi2          (const float& GlbTrkNormChi2)           { GlbTrkNormChi2_ = GlbTrkNormChi2                    ; }
      void getInTrkNormChi2           (const float& InTrkNormChi2)            { InTrkNormChi2_ = InTrkNormChi2                      ; }
      void getIsGlobalMuon            (const float& IsGlobalMuon)             { IsGlobalMuon_ = IsGlobalMuon                        ; }
      void getIsLooseMuon             (const float& IsLooseMuon)              { IsLooseMuon_ = IsLooseMuon                          ; }
      void getIsPFMuon                (const float& IsPFMuon)                 { IsPFMuon_ = IsPFMuon                                ; }
      void getIsSoftMuon              (const float& IsSoftMuon)               { IsSoftMuon_ = IsSoftMuon                            ; }
      void getIsTightMuon             (const float& IsTightMuon)              { IsTightMuon_ = IsTightMuon                          ; }
      void getIsTrackerMuon           (const float& IsTrackerMuon)            { IsTrackerMuon_ = IsTrackerMuon                      ; }
      void getIso04                   (const float& Iso04)                    { Iso04_ = Iso04                                      ; }
      void getKey                     (const float& Key)                      { Key_ = Key                                          ; }
      void getMass                    (const float& Mass)                     { Mass_ = Mass                                        ; }
      void getNumberMatchedStations   (const float& NumberMatchedStations)    { NumberMatchedStations_ = NumberMatchedStations      ; }
      void getNumberOfPixelLayers     (const float& NumberOfPixelLayers)      { NumberOfPixelLayers_ = NumberOfPixelLayers          ; }
      void getNumberOfValidTrackerHits(const float& NumberOfValidTrackerHits) { NumberOfValidTrackerHits_ = NumberOfValidTrackerHits; } 
      void getNumberTrackerLayers     (const float& NumberTrackerLayers)      { NumberTrackerLayers_ = NumberTrackerLayers          ; }
      void getNumberValidMuonHits     (const float& NumberValidMuonHits )     { NumberValidMuonHits_ = NumberValidMuonHits          ; }
      void getNumberValidPixelHits    (const float& NumberValidPixelHits )    { NumberValidPixelHits_ = NumberValidPixelHits        ; }
      void getPhi                     (const float& Phi )                     { Phi_ = Phi                                          ; }
      void getPt                      (const float& Pt )                      { Pt_ = Pt                                            ; }
      void getSumChargedHadronPt      (const float& SumChargedHadronPt)       { SumChargedHadronPt_ = SumChargedHadronPt            ; }
      void getSumNeutralHadronPt      (const float& SumNeutralHadronPt)       { SumNeutralHadronPt_ = SumNeutralHadronPt            ; }
      void getSumPUPt                 (const float& SumPUPt)                  { SumPUPt_ = SumPUPt                                  ; }
      void getSumPhotonPt             (const float& SumPhotonPt)              { SumPhotonPt_ = SumPhotonPt                          ; }

    protected:

      int   index_                   ;
      float Charge_                  ;
      float D0_                      ;
      float D0err_                   ;
      float Dxy_                     ;
      float Dxyerr_                  ;
      float Dz_                      ;
      float Dzerr_                   ;
      float E_                       ;
      float Eta_                     ;
      float GenMuonCharge_           ;
      float GenMuonE_                ;
      float GenMuonEta_              ;
      float GenMuonPhi_              ;
      float GenMuonPt_               ;
      float GenMuonY_                ;
      float GlbTrkNormChi2_          ;
      float InTrkNormChi2_           ;
      float IsGlobalMuon_            ;
      float IsLooseMuon_             ;
      float IsPFMuon_                ;
      float IsSoftMuon_              ;
      float IsTightMuon_             ;
      float IsTrackerMuon_           ;
      float Iso04_                   ;
      float Key_                     ;
      float Mass_                    ;
      float NumberMatchedStations_   ;
      float NumberOfPixelLayers_     ;
      float NumberOfValidTrackerHits_;
      float NumberTrackerLayers_     ;
      float NumberValidMuonHits_     ;
      float NumberValidPixelHits_    ;
      float Phi_                     ;
      float Pt_                      ;
      float SumChargedHadronPt_      ;
      float SumNeutralHadronPt_      ;
      float SumPUPt_                 ;
      float SumPhotonPt_             ;
      float Y_                       ;
  }; 
}

#endif 
