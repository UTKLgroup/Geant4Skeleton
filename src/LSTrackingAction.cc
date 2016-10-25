#include "LSTrackingAction.hh"

LSTrackingAction::LSTrackingAction() {
}

LSTrackingAction::~LSTrackingAction() {
}

void LSTrackingAction::PreUserTrackingAction(const G4Track* track) {

  trkID = track->GetTrackID();
  G4cout << "--Track ID: " << trkID << G4endl;
  G4cout << "--Particle  : " << track->GetParticleDefinition()->GetParticleName() << ". " << G4endl;

  //G4cout << "----ILength   : " << track->GetTrackLength()/(mm) << " (mm). " << G4endl;
  //G4cout << "----IMomentum : " << track->GetMomentum()/(keV) << " (keV). " << G4endl;
  //G4cout << "----IEnergy   : " << track->GetKineticEnergy()/keV << " (keV). " << G4endl;


  //G4cout << "--Track ID : " << track->GetTrackID() << G4endl;
  //G4cout << "--Particle  : " << track->GetParticleDefinition()->GetParticleName() << ". " << G4endl;

  return;
}

void LSTrackingAction::PostUserTrackingAction(const G4Track* track) {
/*
  G4cout << "----FLength   : " << track->GetTrackLength()/(mm) << " (mm). " << G4endl;
  G4cout << "----FMomentum : " << track->GetMomentum()/(keV) << " (keV). " << G4endl;
  G4cout << "----FEnergy   : " << track->GetKineticEnergy()/keV << " (keV). " << G4endl;
*/

/*
  G4AnalysisManager *AnalysisMan = G4AnalysisManager::Instance();
  if (track->GetParticleDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()) {
    //if ((track->GetCurrentStepNumber() == 0)&&(track->GetCreatorProcess()->GetProcessName() == "Scintillation")) {
    //if ((track->GetCurrentStepNumber() == 1)) {
      //track->GetMomentumDirection();
      //AnalysisMan->FillH1(0, 1.298/(track->GetTotalEnergy()/keV));
      //G4cout << "--Wavelength : " << 1.298/(track->GetTotalEnergy()/keV) << " (nm)" << G4endl;
      //G4cout << "--Process    : " << track->GetCreatorProcess()->GetProcessName() << G4endl;
      //G4cout << "--Model      : " << track->GetCreatorModelName() << G4endl;
      //G4cout << "--TE         : " << track->GetTotalEnergy()/keV << " (keV)" << G4endl;
      //G4cout << "--KE         : " << track->GetKineticEnergy()/keV << " (keV)" << G4endl;
      //G4cout << "--ParentID   : " << track->GetParentID() << G4endl;
      //G4cout << "--Step       : " << track->GetCurrentStepNumber()  << "."<< G4endl;
      //G4cout << "--ProperTime  : " << track->GetProperTime()/nanosecond  << " (ns)."<< G4endl;
      AnalysisMan->FillH1(0, track->GetGlobalTime()/nanosecond);
    //}
  }
*/

  //G4cout << "--FTrack ID: " << trkID << G4endl;
  G4cout << G4endl;
  G4cout << G4endl;


  return;
}
