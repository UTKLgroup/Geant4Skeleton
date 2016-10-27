#include "LSSiPMSD.hh"

LSSiPMSD::LSSiPMSD(G4String name) : G4VSensitiveDetector(name) {
  G4String HCname;

  collectionName.insert(HCname = "SiPMHitsCollection");
  HCID = -1;
}

LSSiPMSD::~LSSiPMSD() {
}

void LSSiPMSD::Initialize(G4HCofThisEvent * hitsCE) {
  fSiPMHitCollection = new LSSiPMHitsCollection(SensitiveDetectorName, collectionName[0]);
  if (HCID < 0) {
    HCID = GetCollectionID(0);
  }

  hitsCE->AddHitsCollection(HCID, fSiPMHitCollection);
}

G4bool LSSiPMSD::ProcessHits(G4Step * aStep, G4TouchableHistory *) {
  G4StepPoint * preStep = aStep->GetPreStepPoint();
  G4TouchableHistory * touchable = (G4TouchableHistory *) (preStep->GetTouchable());

  LSSiPMHit * newHit = new LSSiPMHit();
  newHit->SetEnergy(aStep->GetPreStepPoint()->GetTotalEnergy());
  newHit->SetParticle(aStep->GetTrack()->GetDefinition());
  fSiPMHitCollection->insert(newHit);
  G4cout << "SiPM striked!" << G4endl;

  return true;
}

void LSSiPMSD::EndOfEvent(G4HCofThisEvent *) {
}

void LSSiPMSD::clear() {
}

void LSSiPMSD::DrawAll() {
}

void LSSiPMSD::PrintAll() {
}
