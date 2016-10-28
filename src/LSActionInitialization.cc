#include "LSActionInitialization.hh"

LSActionInitialization::LSActionInitialization() : G4VUserActionInitialization() {
}

LSActionInitialization::~LSActionInitialization() {
}

void LSActionInitialization::Build() const {
  SetUserAction(new LSPrimaryGeneratorAction("./setup.file"));

  //LSRunAction* runAction = new LSRunAction();
  //SetUserAction(runAction);


  LSTrackingAction* trackingAction = new LSTrackingAction();
  SetUserAction(trackingAction);

  LSEventAction* eventAction = new LSEventAction();
  SetUserAction(eventAction);

  //LSSteppingAction* steppingAction = new LSSteppingAction();
  //SetUserAction(steppingAction);


  return;
}
