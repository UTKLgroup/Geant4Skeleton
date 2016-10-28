#include "LSDetectorConstruction.hh"

LSDetectorConstruction::LSDetectorConstruction() : G4VUserDetectorConstruction() {
}

LSDetectorConstruction::~LSDetectorConstruction() {
}

void LSDetectorConstruction::BuildMaterial() {
  G4NistManager * nist = G4NistManager::Instance();
  G4double z, a, density;

  // Air
  fAir = nist->FindOrBuildMaterial("G4_AIR");

  // Aluminum
  fAl = nist->FindOrBuildMaterial("G4_Al");

  // Silicon
  fSiPMMat = nist->FindOrBuildMaterial("G4_Si");

  // Liquid Argon (Properties data taken from LArSOFT)
  fLAr = new G4Material("LAr", z = 18., a = 39.948 * g/mole, density = 1.3954 * g/cm3);
  G4double LAr_ScintEnergy[] = {6.0*eV, 6.7*eV, 7.1*eV, 7.4*eV, 7.7*eV, 7.9*eV, 8.1*eV, 8.4*eV,  8.5*eV, 8.6*eV, 8.8*eV, 9.0*eV, 9.1*eV, 9.4*eV, 9.8*eV, 10.4*eV, 10.7*eV};
  // Dung's LAr Scintilation correction
  for (unsigned int i = 0; i < 17; i++) {
    LAr_ScintEnergy[i] += 1.7*eV;
  }
  const G4int LArScintNum = sizeof(LAr_ScintEnergy)/sizeof(G4double);
  G4double LAr_SCINT[] = {0.0, 0.04, 0.12, 0.27, 0.44, 0.62, 0.80, 0.91, 0.92, 0.85, 0.70, 0.50, 0.31, 0.13, 0.04,  0.01, 0.0};
  assert(sizeof(LAr_SCINT) == sizeof(LAr_ScintEnergy));
  G4double LAr_RIndEnergy[] = {1.900*eV,  2.934*eV,  3.592*eV,  5.566*eV,  6.694*eV,  7.540*eV,  8.574*eV,  9.044*eV,  9.232*eV, 9.420*eV,  9.514*eV,  9.608*eV,  9.702*eV,  9.796*eV,  9.890*eV,  9.984*eV,  10.08*eV,  10.27*eV,  10.45*eV,  10.74*eV,  10.92*eV};
  const G4int LArRIndNum = sizeof(LAr_RIndEnergy)/sizeof(G4double);
  G4double LAr_RIND[] = {1.232, 1.236, 1.240, 1.261, 1.282, 1.306, 1.353, 1.387, 1.404, 1.423, 1.434, 1.446, 1.459, 1.473, 1.488, 1.505,  1.524, 1.569, 1.627, 1.751, 1.879};
  assert(sizeof(LAr_RIND) == sizeof(LAr_RIndEnergy));
  G4double LAr_AbsLEnergy[] = {4*eV, 5*eV, 6*eV, 7*eV, 8*eV, 9*eV, 10*eV, 11*eV};
  const G4int LArAbsLNum = sizeof(LAr_AbsLEnergy)/sizeof(G4double);
  G4double LAr_ABSL[]  = {2000.*cm, 2000.*cm, 2000.*cm, 2000.*cm, 2000.*cm, 2000.*cm, 2000.*cm, 2000.*cm};
  assert(sizeof(LAr_ABSL) == sizeof(LAr_AbsLEnergy));
  fLAr_mt = new G4MaterialPropertiesTable();
  fLAr_mt->AddProperty("FASTCOMPONENT", LAr_ScintEnergy, LAr_SCINT, LArScintNum);
  fLAr_mt->AddProperty("SLOWCOMPONENT", LAr_ScintEnergy, LAr_SCINT, LArScintNum);
  fLAr_mt->AddProperty("RINDEX",        LAr_RIndEnergy, LAr_RIND,  LArRIndNum);
  fLAr_mt->AddProperty("ABSLENGTH",     LAr_AbsLEnergy, LAr_ABSL,  LArAbsLNum);
  //fLAr_mt->AddConstProperty("SCINTILLATIONYIELD", 24000./MeV);
  fLAr_mt->AddConstProperty("SCINTILLATIONYIELD", 1./MeV); // debug light yield
  fLAr_mt->AddConstProperty("RESOLUTIONSCALE", 1.0);
  fLAr_mt->AddConstProperty("FASTTIMECONSTANT", 6.*ns);
  fLAr_mt->AddConstProperty("SLOWTIMECONSTANT", 1590.*ns);
  fLAr_mt->AddConstProperty("YIELDRATIO", 0.5);
  fLAr->SetMaterialPropertiesTable(fLAr_mt);
  fLAr->GetIonisation()->SetBirksConstant(0.69*mm/MeV);

  return;
}

G4VPhysicalVolume * LSDetectorConstruction::Construct() {
  BuildMaterial();

  // Overlapping check
  G4bool checkOverlaps = true;

  // LAr Volume
  larvolBox = new G4Tubs("LArVolumeBox",
            0,
            9 * inch,
            30 * inch,
            0. * deg,
            360. * deg);
  larvolLog = new G4LogicalVolume(larvolBox, fLAr, "LArVolumeLog", 0, 0, 0);

  // Aluminum housing
  larhouseBox = new G4Tubs("LArHouseBox",
            9 * inch,
            9.5 * inch,
            30 * inch,
            0. * deg,
            360. * deg);
  larhouseLog = new G4LogicalVolume(larhouseBox, fAl, "LArHouseLog", 0, 0, 0);
  larlidBox = new G4Tubs("LArLidBox",
            0 * inch,
            9.5 * inch,
            0.5 * inch,
            0. * deg,
            360. * deg);
  larlidLog = new G4LogicalVolume(larlidBox, fAl, "LArLidLog", 0, 0, 0);

  // SiPM surfaces
  G4Box* sipmA = new G4Box("sipmA", 1.5 * mm, 1.5 * mm, 0.5 * mm);
  G4Box* sipmB = new G4Box("sipmB", 1.5 * mm, 1.5 * mm, 0.5 * mm);
  G4Box* sipmC = new G4Box("sipmC", 1.5 * mm, 1.5 * mm, 0.5 * mm);
  G4LogicalVolume* sipmALog = new G4LogicalVolume(sipmA, fSiPMMat, "sipmALog", 0, 0, 0);
  G4LogicalVolume* sipmBLog = new G4LogicalVolume(sipmB, fSiPMMat, "sipmBLog", 0, 0, 0);
  G4LogicalVolume* sipmCLog = new G4LogicalVolume(sipmC, fSiPMMat, "sipmCLog", 0, 0, 0);

/*
  G4double maxStep = 0.25*mm;
  G4UserLimits* fStepLimit = new G4UserLimits(maxStep);
  sipmALog->SetUserLimits(fStepLimit);
  sipmBLog->SetUserLimits(fStepLimit);
  sipmCLog->SetUserLimits(fStepLimit);
*/

/*
  // Sensitive Detectors (SiPMs)
  G4String SiPMname;
  LSSiPMSD* sipmsd = new LSSiPMSD(SiPMname = "SiPMSD");

  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  SDman->AddNewDetector(sipmsd);
  sipmALog->SetSensitiveDetector(sipmsd);
*/

  // World
  worldBox = new G4Box("WorldBox", world_hx/2., world_hy/2., world_hz/2.);
  worldLog = new G4LogicalVolume(worldBox, fAir, "WorldLog");


  // Placing Detectors
  G4VPhysicalVolume* sipmAPhy = new G4PVPlacement(0, G4ThreeVector(0, 0, -25 * inch), sipmALog, "sipmAPhy", larvolLog, false, 0, false);
  G4VPhysicalVolume* sipmBPhy = new G4PVPlacement(0, G4ThreeVector(0, -40 * mm, -25 * inch), sipmBLog, "sipmBPhy", larvolLog, false, 0, false);
  G4VPhysicalVolume* sipmCPhy = new G4PVPlacement(0, G4ThreeVector(0, 40 * mm, -25 * inch), sipmCLog, "sipmCPhy", larvolLog, false, 0,false);

  // Housing and LAr volume
  larhousePhy = new G4PVPlacement(0, G4ThreeVector(), larhouseLog, "LArVolumePhy", worldLog, false, 0);
  larlidAPhy = new G4PVPlacement(0, G4ThreeVector(0, 0, -30.5*inch), larlidLog, "LArLidAPhy", worldLog, false, 0);
  larlidBPhy = new G4PVPlacement(0, G4ThreeVector(0, 0, +30.5*inch), larlidLog, "LArLidBPhy", worldLog, false, 0);
  larvolPhy = new G4PVPlacement(0, G4ThreeVector(), larvolLog, "LArVolumePhy", worldLog, false, 0);

  // Housing Surfaces Properties
  G4OpticalSurface* AluminumLArSurface = new G4OpticalSurface("AluminumLArSurface");
  AluminumLArSurface->SetType(dielectric_metal);
  AluminumLArSurface->SetFinish(polished);
  AluminumLArSurface->SetModel(glisur);
  G4LogicalBorderSurface* sfhousing = new G4LogicalBorderSurface("AluminumLArSurface", larvolPhy, larhousePhy, AluminumLArSurface);
  G4LogicalBorderSurface* sflidA = new G4LogicalBorderSurface("AluminumLArSurface", larvolPhy, larlidAPhy, AluminumLArSurface);
  G4LogicalBorderSurface* sflidB = new G4LogicalBorderSurface("AluminumLArSurface", larvolPhy, larlidBPhy, AluminumLArSurface);

  G4double AlLArpp[] = {4*eV, 5*eV, 6*eV, 7*eV, 8*eV, 9*eV, 10*eV, 11*eV};
  const G4int AlLArnum = sizeof(AlLArpp)/sizeof(G4double);
  G4double AlLArReflectivity[] = {0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3};
  assert(sizeof(AlLArReflectivity) == sizeof(AlLArpp));
  G4double AlLArEfficiency[] = {0., 0., 0., 0., 0., 0., 0., 0.};
  assert(sizeof(AlLArEfficiency) == sizeof(AlLArpp));

  G4MaterialPropertiesTable* AluminumLArSurfaceProperty = new G4MaterialPropertiesTable();
  AluminumLArSurfaceProperty->AddProperty("REFLECTIVITY", AlLArpp, AlLArReflectivity, AlLArnum);
  AluminumLArSurfaceProperty->AddProperty("EFFICIENCY", AlLArpp, AlLArEfficiency, AlLArnum);
  AluminumLArSurface->SetMaterialPropertiesTable(AluminumLArSurfaceProperty);

  // Placing World
  worldPhy = new G4PVPlacement(0, G4ThreeVector(), worldLog, "WorldPhy", 0, false, 0, checkOverlaps);

  return worldPhy;
}
