#ifndef LSTrackingAction_h
#define LSTrackingAction_h 1

#include "G4UserTrackingAction.hh"
#include "G4SystemOfUnits.hh"
#include "G4Track.hh"
#include "globals.hh"
#include "G4OpticalPhoton.hh"
#include "G4VProcess.hh"

#include "LSAnalysis.hh"

class LSTrackingAction : public G4UserTrackingAction {
public:
  LSTrackingAction();
  virtual ~LSTrackingAction();

  virtual void PreUserTrackingAction(const G4Track*);
  virtual void PostUserTrackingAction(const G4Track*);

private:
  G4int trkID;
};

#endif
