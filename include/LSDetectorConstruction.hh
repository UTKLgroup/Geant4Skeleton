#ifndef LSDetectorConstruction_h
#define LSDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class LSDetectorConstruction : public G4VUserDetectorConstruction {
public:
  LSDetectorConstruction();
  virtual ~LSDetectorConstruction();
  virtual G4VPhysicalVolume* Construct();
  virtual void BuildMaterial();

private:
  /**
   * WORLD GEOMETRY
   */
  G4Box * worldBox;
  G4LogicalVolume * worldLog;
  G4VPhysicalVolume * worldPhy;
  // Dimensions of world volume
  G4double world_hx = 1.0 * m;
  G4double world_hy = 1.0 * m;
  G4double world_hz = 1.0 * m;

  /**
   * MATERIAL LISTS
   */
  G4Material * Air;

};
#endif
