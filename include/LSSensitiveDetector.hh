#ifndef LSSensitiveDetector_h
#define LSSensitiveDetector_h 1

#include "G4VSensitiveDetector.hh"

#include "LSSensitiveDetectorHit.hh"

#include <vector>

class G4Step;
class G4HCofThisEvent;

/// The hits are accounted in hits in ProcessHits() function which is called
/// by Geant4 kernel at each step. A hit is created with each step with non zero
/// energy deposit.

class LSSensitiveDetector : public G4VSensitiveDetector {
  public:
    LSSensitiveDetector(const G4String& name, const G4String& hitsCollectionName);
    virtual ~LSSensitiveDetector();

    // Methods from base class
    // Users need to overwrite
    virtual void   Initialize(G4HCofThisEvent* hitCollection);
    virtual G4bool ProcessHits(G4Step* step);
    virtual void   EndOfEvent(G4HCofThisEvent* hitCollection);

  private:
    LSSensitiveDetectorHitsCollection* fHitsCollection;
};
#endif
