#ifndef LSSiPMSD_h
#define LSSiPMSD_h 1

#include "LSSiPMHit.hh"
#include "LSDetectorConstruction.hh"

#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"

class G4Step;
class G4HCofThisEvent;

class LSSiPMSD : public G4VSensitiveDetector {
public:
  LSSiPMSD(G4String name);
  virtual ~LSSiPMSD();

  virtual void Initialize(G4HCofThisEvent *);
  virtual G4bool ProcessHits(G4Step * aStep, G4TouchableHistory *);
  virtual void EndOfEvent(G4HCofThisEvent *);
  virtual void clear();
  void DrawAll();
  void PrintAll();

private:
  G4int HCID;
  LSSiPMHitsCollection * fSiPMHitCollection;
};

#endif
