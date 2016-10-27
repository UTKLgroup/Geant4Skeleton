#ifndef LSDetectorConstruction_h
#define LSDetectorConstruction_h 1

#include "LSSiPMSD.hh"

#include "G4SDManager.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4MaterialTable.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4Tubs.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4OpticalSurface.hh"
#include "globals.hh"
#include "G4UserLimits.hh"
#include "G4LogicalSkinSurface.hh"

static const G4double inch = 2.54*cm;
static const G4double dm = 10*cm;

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
   * WORLD
   */
  G4double world_hx = 3.0 * m;
  G4double world_hy = 3.0 * m;
  G4double world_hz = 3.0 * m;
  G4Box * worldBox;
  G4LogicalVolume * worldLog;
  G4VPhysicalVolume * worldPhy;

/*
  G4double larvol_hx = 4.5 * m;
  G4double larvol_hy = 4.5 * m;
  G4double larvol_hz = 4.5 * m;
  G4Box * larvolBox;
  G4LogicalVolume * larvolLog;
  G4VPhysicalVolume * larvolPhy;

  G4double larhouse_thickx = 10.0 * cm; // Wall thickness
  G4double larhouse_thicky = 10.0 * cm;
  G4double larhouse_thickz = 10.0 * cm;
  G4double larhouse_hx = larvol_hx + larhouse_thickx * 2.;
  G4double larhouse_hy = larvol_hy + larhouse_thicky * 2.;
  G4double larhouse_hz = larvol_hz + larhouse_thickz * 2.;
  G4Box * larhouseBox;
  G4LogicalVolume * larhouseLog;
  G4VPhysicalVolume * larhousePhy;
*/

  G4Tubs * larvolBox;
  G4LogicalVolume * larvolLog;
  G4VPhysicalVolume * larvolPhy;

  G4Tubs * larhouseBox;
  G4LogicalVolume * larhouseLog;
  G4VPhysicalVolume * larhousePhy;

  G4Tubs * larlidBox;
  G4LogicalVolume * larlidLog;
  G4VPhysicalVolume * larlidAPhy;
  G4VPhysicalVolume * larlidBPhy;

  /**
   * MATERIALS
   */
  G4Material * fAir;
  G4Material * fLAr;
  G4Material * fAl;
  G4Material * fSiPMMat;

  /**
   * MATERIAL PROPERTY TABLE
   */
  G4MaterialPropertiesTable* fLAr_mt;
};


#endif
