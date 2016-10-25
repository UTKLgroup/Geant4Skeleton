#include "LSEventAction.hh"

LSEventAction::LSEventAction() : G4UserEventAction() {
}

LSEventAction::~LSEventAction() {
}

void LSEventAction::BeginOfEventAction(const G4Event * event) {
  evtID = event->GetEventID();
  G4cout << "-Event number: " << evtID << " started." << G4endl;

  return;
}

void LSEventAction::EndOfEventAction(const G4Event * event) {
  event->GetEventID();

  return;
}
