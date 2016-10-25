#include "LSRunAction.hh"

LSRunAction::LSRunAction() : G4UserRunAction() {
}

LSRunAction::~LSRunAction() {
}

void LSRunAction::BeginOfRunAction(const G4Run * run) {

  runID = run->GetRunID();
  G4cout << "Run number: " << runID << " started." << G4endl;

  G4AnalysisManager *AnalysisMan = G4AnalysisManager::Instance();
  AnalysisMan->OpenFile("OutputData");
  AnalysisMan->CreateH1("STD", "Scint. Time Distribution", 100, 0, 25);
  //AnalysisMan->CreateH1("CPW", "Cherenkov Photon Wavelength", 100, 10, 2100);
  //AnalysisMan->CreateH1("CAD", "Cherenkov Angle Distribution", 90, 0, 90);
  G4cout << "Analysis Histogram is initialized." << G4endl;

  return;
}

void LSRunAction::EndOfRunAction(const G4Run * run) {

  runID = run->GetRunID();

  G4AnalysisManager *AnalysisMan = G4AnalysisManager::Instance();
  AnalysisMan->Write();
  AnalysisMan->CloseFile();
  G4cout << "Analysis Histogram is terminated." << G4endl;

  G4cout << "----------------------------------------------------------" << G4endl << G4endl << G4endl;

  return;
}
