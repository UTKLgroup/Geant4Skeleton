#ifndef LSSteppingAction_h
#define LSSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4VProcess.hh"
#include "G4SystemOfUnits.hh"
#include "G4OpticalPhoton.hh"
#include "globals.hh"

#include "LSAnalysis.hh"

class LSSteppingAction : public G4UserSteppingAction {
public:
  LSSteppingAction();
  virtual ~LSSteppingAction();

  virtual void UserSteppingAction(const G4Step*);

};

#endif
