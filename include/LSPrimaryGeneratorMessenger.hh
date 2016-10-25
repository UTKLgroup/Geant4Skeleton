#ifndef LSPrimaryGeneratorMessenger_h
#define LSPrimaryGeneratorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class LSPrimaryGeneratorAction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithoutParameter;

class LSPrimaryGeneratorMessenger: public G4UImessenger
{
  public:
    LSPrimaryGeneratorMessenger(LSPrimaryGeneratorAction*);
   ~LSPrimaryGeneratorMessenger();

    void SetNewValue(G4UIcommand*, G4String);

  private:
    LSPrimaryGeneratorAction*      Action;
    G4UIdirectory*               CRYDir;
    G4UIcmdWithAString*          FileCmd;
    G4UIcmdWithAString*          InputCmd;
    G4UIcmdWithoutParameter*     UpdateCmd;
    std::string* MessInput;
};

#endif
