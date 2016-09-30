#include "LSActionInitialization.hh"
#include "LSPrimaryGeneratorAction.hh"
#include "LSEventAction.hh"
#include "LSSteppingAction.hh"

LSActionInitialization::LSActionInitialization() : G4VUserActionInitialization() {
}

LSActionInitialization::~LSActionInitialization() {
}

void LSActionInitialization::Build() const {
  SetUserAction(new LSPrimaryGeneratorAction);

  // LSRunAction* runAction = new LSRunAction;
  // SetUserAction(runAction);

  // LSEventAction* eventAction = new LSEventAction(runAction);
  // SetUserAction(eventAction);

  // SetUserAction(new LSSteppingAction(eventAction));
}
