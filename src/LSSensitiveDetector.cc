#include "LSSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"


LSSensitiveDetector::LSSensitiveDetector(const G4String& name, const G4String& hitsCollectionName)
: G4VSensitiveDetector(name),
  fHitsCollection(NULL) {
  collectionName.insert(hitsCollectionName);
}

LSSensitiveDetector::~LSSensitiveDetector() {
}

void LSSensitiveDetector::Initialize(G4HCofThisEvent * hce) {
  // Create hits collection
  fHitsCollection = new LSSensitiveDetectorHitsCollection(SensitiveDetectorName, collectionName[0]);

  // Add this collection in hce
  G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection(hcID, fHitsCollection);
}

G4bool LSSensitiveDetector::ProcessHits(G4Step * aStep) {
  LSSensitiveDetectorHit * aHit = new LSSensitiveDetectorHit();
  fHitsCollection->insert(aHit);
  return true;
}

void LSSensitiveDetector::EndOfEvent(G4HCofThisEvent *) {
}
