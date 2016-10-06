#include "LSSensitiveDetectorHit.hh"

G4ThreadLocal G4Allocator<LSSensitiveDetectorHit> * LSSensitiveDetectorHitAllocator = 0;

LSSensitiveDetectorHit::LSSensitiveDetectorHit() : G4VHit() {
}

LSSensitiveDetectorHit::~LSSensitiveDetectorHit() {
}

LSSensitiveDetectorHit::LSSensitiveDetectorHit(const LSSensitiveDetectorHit& right) : G4VHit() {
}

const LSSensitiveDetectorHit& LSSensitiveDetectorHit::operator=(const LSSensitiveDetectorHit& right) {
  return *this;
}

G4int LSSensitiveDetectorHit::operator==(const LSSensitiveDetectorHit& right) const {
  return ( this == &right ) ? 1 : 0;
}

void LSSensitiveDetectorHit::Draw() {
}

void LSSensitiveDetectorHit::Print() {
}
