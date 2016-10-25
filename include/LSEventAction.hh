#ifndef LSEventAction_h
#define LSEventAction_h 1

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UserEventAction.hh"
#include "G4TrajectoryContainer.hh"
#include "globals.hh"

class LSRunAction;

class LSEventAction : public G4UserEventAction {
public:
  LSEventAction();
  virtual ~LSEventAction();

  virtual void BeginOfEventAction(const G4Event* event);
  virtual void EndOfEventAction(const G4Event* event);

private:
  G4int evtID;
};

#endif
