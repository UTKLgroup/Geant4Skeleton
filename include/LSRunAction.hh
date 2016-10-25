#ifndef LSRunAction_h
#define LSRunAction_h 1

#include "LSAnalysis.hh"

#include "G4UserRunAction.hh"
#include "G4Parameter.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"
#include "globals.hh"

class LSRunAction : public G4UserRunAction {
public:
  LSRunAction();
  virtual ~LSRunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);

private:
  G4int runID;
};

#endif
