#include "LSSiPMHit.hh"

G4Allocator<LSSiPMHit> LSSiPMHitAllocator;

LSSiPMHit::LSSiPMHit() {
}

LSSiPMHit::~LSSiPMHit() {
}

G4int LSSiPMHit::operator==(const LSSiPMHit &right) const {
  return (this == &right) ? 1 : 0;
}

void LSSiPMHit::Draw() {
}

void LSSiPMHit::Print() {
}
