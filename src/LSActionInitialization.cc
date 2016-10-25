#include "LSActionInitialization.hh"

LSActionInitialization::LSActionInitialization() : G4VUserActionInitialization() {
}

LSActionInitialization::~LSActionInitialization() {
}

void LSActionInitialization::Build() const {
  SetUserAction(new LSPrimaryGeneratorAction("./setup.file"));
/*
  LSRunAction* runAction = new LSRunAction();
  SetUserAction(runAction);

  LSEventAction* eventAction = new LSEventAction();
  SetUserAction(eventAction);

  LSTrackingAction* trackingAction = new LSTrackingAction();
  SetUserAction(trackingAction);

  LSSteppingAction* steppingAction = new LSSteppingAction();
  SetUserAction(steppingAction);
*/


  return;
}
