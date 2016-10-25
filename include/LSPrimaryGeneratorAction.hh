#ifndef LSPrimaryGeneratorAction_h
#define LSPrimaryGeneratorAction_h 1

#include "LSPrimaryGeneratorMessenger.hh"
#include "RNGWrapper.hh"

#include <vector>
#include <iomanip>


#include "G4Event.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4DataVector.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleGun.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "Randomize.hh"
#include "globals.hh"

#include "CRYSetup.h"
#include "CRYGenerator.h"
#include "CRYParticle.h"
#include "CRYUtils.h"

class G4Event;

class LSPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    LSPrimaryGeneratorAction(const char * filename);
    ~LSPrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event* anEvent);
    void InputCRY();
    void UpdateCRY(std::string* MessInput);
    void CRYFromFile(G4String newValue);

  private:
    std::vector<CRYParticle*> *vect; // vector of generated particles
    G4ParticleTable* particleTable;
    G4ParticleGun* particleGun;
    CRYGenerator* gen;
    G4int InputState;
    LSPrimaryGeneratorMessenger* gunMessenger;
};

#endif
