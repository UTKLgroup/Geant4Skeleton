#include "LSPhysicsList.hh"

LSPhysicsList::LSPhysicsList() : G4VModularPhysicsList() {
  SetVerboseLevel(0);

  /**
   * EM Physics
   */
  RegisterPhysics(new G4EmStandardPhysics());

  //G4DecayPhysics* decay = new G4DecayPhysics();
  //decay->SetVerboseLevel(0);
  //RegisterPhysics(decay);

  //G4HadronElasticPhysicsHP* hepHP = new G4HadronElasticPhysicsHP();
  //hepHP->SetVerboseLevel(0);
  //RegisterPhysics(hepHP);


  /**
   * Optical Physics
   */

  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  opticalPhysics->Configure(kCerenkov, false);
  opticalPhysics->Configure(kScintillation, true);
  opticalPhysics->Configure(kAbsorption, true);
  opticalPhysics->Configure(kMieHG, false);
  opticalPhysics->Configure(kRayleigh, true);
  opticalPhysics->Configure(kBoundary, true);
  opticalPhysics->Configure(kWLS, false);
  opticalPhysics->SetScintillationYieldFactor(0.5);
  opticalPhysics->SetScintillationExcitationRatio(0.4);
  //opticalPhysics->SetMaxNumPhotonsPerStep(10000);
  //opticalPhysics->SetMaxBetaChangePerStep(10.0);
  //opticalPhysics->SetTrackSecondariesFirst(kCerenkov, true);
  opticalPhysics->SetTrackSecondariesFirst(kScintillation, false);
  RegisterPhysics(opticalPhysics);
}

LSPhysicsList::~LSPhysicsList() {
}

void LSPhysicsList::SetCuts() {
  G4VUserPhysicsList::SetCuts();
}
