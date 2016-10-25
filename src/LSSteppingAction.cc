#include "LSSteppingAction.hh"

LSSteppingAction::LSSteppingAction() {
}

LSSteppingAction::~LSSteppingAction() {
}

void LSSteppingAction::UserSteppingAction(const G4Step* step) {


  G4Track* theCurrentTrack = step->GetTrack();
  G4AnalysisManager *AnalysisMan = G4AnalysisManager::Instance();
  //if (theCurrentTrack->GetTrackID() == 1) {
  //if (theCurrentTrack->GetParticleDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()) {
  //if (theCurrentTrack->GetCurrentStepNumber() == 2) {
  //  G4cout << "-----Post Local Time : " << step->GetPostStepPoint()->GetLocalTime()/nanosecond << G4endl;
  //}

  if (theCurrentTrack->GetParticleDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()) {
    if (step->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "sipmAPhy") {
      G4cout << "Hit in SiPM A!" << G4endl;
    }
    if (step->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "sipmBPhy") {
      G4cout << "Hit in SiPM B!" << G4endl;
    }
    if (step->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "sipmCPhy") {
      G4cout << "Hit in SiPM C!" << G4endl;
    }
  }


  //if () {
    //G4cout << "-----Track           : " << theCurrentTrack->GetTrackID() << G4endl;
    //G4cout << "-----Parent          : " << theCurrentTrack->GetParentID() << G4endl;
    //G4cout << "-----Step            : " << theCurrentTrack->GetCurrentStepNumber() << G4endl;
    //G4cout << "-----Particle        : " << theCurrentTrack->GetParticleDefinition()->GetParticleName() << G4endl;
    //G4cout << "-----Step Delta Time : " << step->GetDeltaTime()/nanosecond << G4endl;
    //G4cout << "-----Particle   : " << theCurrentTrack->GetParticleDefinition()->GetParticleName() << G4endl;
    //G4cout << "-----Pre Local Time  : " << step->GetPreStepPoint()->GetLocalTime()/nanosecond << G4endl;
    //G4cout << "-----Pre Process     : " << step->GetPreStepPoint()->GetProcessDefinedStep()->GetProcessName() << G4endl;
    //G4cout << "-----Post Local Time : " << step->GetPostStepPoint()->GetLocalTime()/nanosecond << G4endl;
    //AnalysisMan->FillH1(0, step->GetPostStepPoint()->GetLocalTime()/nanosecond);

    //G4cout << "-----Post Process    : " << step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName() << G4endl;
    //G4cout << G4endl;
    //G4cout << G4endl;
    //G4cout << G4endl;
    //G4cout << "-----Volume    : " << theCurrentTrack->GetVolume()->GetName() << G4endl;
    //G4cout << G4endl;
    //G4cout << "Length: " << step->GetStepLength()/mm << " (mm). ";
    //G4cout << "EnDepo: " << step->GetTotalEnergyDeposit()/keV << " (keV). " << G4endl;
  //}


/*


*/

  return;
}
