#include "LSPrimaryGeneratorAction.hh"

LSPrimaryGeneratorAction::LSPrimaryGeneratorAction(const char * inputfile) {
  //G4cout << "------------------LSPrimaryGeneratorAction" << G4endl;
  // define a particle gun
  particleGun = new G4ParticleGun();

  // Read the cry input file
  std::ifstream inputFile;
  inputFile.open(inputfile, std::ios::in);
  char buffer[1000];

  if (inputFile.fail()) {
    if ( *inputfile != 0) { // ....only complain if a filename was given
      G4cout << "LSPrimaryGeneratorAction: Failed to open CRY input file= " << inputfile << G4endl;
    }
    InputState = -1;
  } else {
    std::string setupString("");
    while ( !inputFile.getline(buffer, 1000).eof()) {
      setupString.append(buffer);
      setupString.append(" ");
    }

    G4cout << setupString << G4endl;

    CRYSetup * setup = new CRYSetup(setupString, "./data");

    gen = new CRYGenerator(setup);

    // set random number generator
    RNGWrapper<CLHEP::HepRandomEngine>::set(CLHEP::HepRandom::getTheEngine(), &CLHEP::HepRandomEngine::flat);
    setup->setRandomFunction(RNGWrapper<CLHEP::HepRandomEngine>::rng);
    InputState = 0;
  }
  // create a vector to store the CRY particle properties
  vect = new std::vector<CRYParticle *>;

  // Create the table containing all particle names
  particleTable = G4ParticleTable::GetParticleTable();

  // Create the messenger file
  gunMessenger = new LSPrimaryGeneratorMessenger(this);
}

LSPrimaryGeneratorAction::~LSPrimaryGeneratorAction() {
  //G4cout << "------------------~LSPrimaryGeneratorAction" << G4endl;
}

void LSPrimaryGeneratorAction::InputCRY() {
  //G4cout << "------------------InputCRY" << G4endl;
  InputState = 1;
}

void LSPrimaryGeneratorAction::UpdateCRY(std::string * MessInput) {
  //G4cout << "------------------UpdateCRY" << G4endl;
  CRYSetup * setup = new CRYSetup(*MessInput, "./data");

  gen = new CRYGenerator(setup);

  // set random number generator
  RNGWrapper<CLHEP::HepRandomEngine>::set(CLHEP::HepRandom::getTheEngine(), &CLHEP::HepRandomEngine::flat);
  setup->setRandomFunction(RNGWrapper<CLHEP::HepRandomEngine>::rng);
  InputState = 0;

}

void LSPrimaryGeneratorAction::CRYFromFile(G4String newValue) {
  //G4cout << "------------------CRYFromFile" << G4endl;
  // Read the cry input file
  std::ifstream inputFile;

  inputFile.open(newValue, std::ios::in);
  char buffer[1000];

  if (inputFile.fail()) {
    G4cout << "Failed to open input file " << newValue << G4endl;
    G4cout << "Make sure to define the cry library on the command line" << G4endl;
    InputState = -1;
  } else {
    std::string setupString("");
    while ( !inputFile.getline(buffer, 1000).eof()) {
      setupString.append(buffer);
      setupString.append(" ");
    }

    CRYSetup * setup = new CRYSetup(setupString, "./data");

    gen = new CRYGenerator(setup);

    // set random number generator
    RNGWrapper<CLHEP::HepRandomEngine>::set(CLHEP::HepRandom::getTheEngine(), &CLHEP::HepRandomEngine::flat);
    setup->setRandomFunction(RNGWrapper<CLHEP::HepRandomEngine>::rng);
    InputState = 0;
  }
}

void LSPrimaryGeneratorAction::GeneratePrimaries(G4Event * anEvent) {
  //G4cout << "------------------GeneratePrimaries" << G4endl;
  if (InputState != 0) {
    G4String * str = new G4String("CRY library was not successfully initialized");
    // G4Exception(*str);
    G4Exception("LSPrimaryGeneratorAction", "1",
                RunMustBeAborted, *str);
  }
  G4String particleName;
  vect->clear();
  gen->timeSimulated();
  gen->genEvent(vect);

  // ....debug output
  G4cout << "\nEvent=" << anEvent->GetEventID() << " "
         << "CRY generated nparticles=" << vect->size()
         << G4endl;

  for ( unsigned j = 0; j < vect->size(); j++) {
    particleName = CRYUtils::partName((*vect)[j]->id());

    // ....debug output

    G4cout << "  "          << particleName << " "
         << "charge="      << (*vect)[j]->charge() << " "
         << std::setprecision(4)
         << "energy (MeV)=" << (*vect)[j]->ke() * MeV << " "
         << "pos (m)"
         << G4ThreeVector((*vect)[j]->x(), (*vect)[j]->y(), (*vect)[j]->z())
         << " " << "direction cosines "
         << G4ThreeVector((*vect)[j]->u(), (*vect)[j]->v(), (*vect)[j]->w())
         << " " << G4endl;

    particleGun->SetParticleDefinition(particleTable->FindParticle((*vect)[j]->PDGid()));
    particleGun->SetParticleEnergy((*vect)[j]->ke() * MeV);
    //particleGun->SetParticlePosition(G4ThreeVector((*vect)[j]->x() * m, (*vect)[j]->y() * m, (*vect)[j]->z() * m));
    //Dung changed this for the cosmic ray for the whole volume.
    particleGun->SetParticlePosition(G4ThreeVector((*vect)[j]->x() * m, (*vect)[j]->y() * m, 1.5 * m));
    particleGun->SetParticleMomentumDirection(G4ThreeVector((*vect)[j]->u(), (*vect)[j]->v(), (*vect)[j]->w()));
    particleGun->SetParticleTime((*vect)[j]->t());
    particleGun->GeneratePrimaryVertex(anEvent);

    delete (*vect)[j];
  }
}
