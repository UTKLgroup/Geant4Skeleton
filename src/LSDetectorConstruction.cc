#include "LSDetectorConstruction.hh"

LSDetectorConstruction::LSDetectorConstruction() : G4VUserDetectorConstruction() {
}

LSDetectorConstruction::~LSDetectorConstruction() {
}

void LSDetectorConstruction::BuildMaterial() {
  G4NistManager * nist = G4NistManager::Instance();

  /**
   * BASIC MATERIAL
   */
  Air = nist->FindOrBuildMaterial("G4_AIR");

}

G4VPhysicalVolume * LSDetectorConstruction::Construct() {

  // Check overlapping
  G4bool checkOverlaps = true;

  // create world volume
  worldBox = new G4Box("World", world_hx, world_hy, world_hz);
  worldLog = new G4LogicalVolume(worldBox, Air, "World");
  worldPhy = new G4PVPlacement(0, G4ThreeVector(), worldLog, "World", 0, false, 0, checkOverlaps);

  return worldPhy;
}
