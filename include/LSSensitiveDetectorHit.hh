#ifndef LSSensitiveDetectorHit_h
#define LSSensitiveDetectorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4UnitsTable.hh"

class LSSensitiveDetectorHit : public G4VHit {
  public:
    LSSensitiveDetectorHit();
    LSSensitiveDetectorHit(const LSSensitiveDetectorHit&);
    virtual ~LSSensitiveDetectorHit();

    // Operators
    const LSSensitiveDetectorHit& operator=(const LSSensitiveDetectorHit&);
    G4int operator==(const LSSensitiveDetectorHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);

    // Methods from base class
    virtual void Draw();
    virtual void Print();
};
typedef G4THitsCollection<LSSensitiveDetectorHit> LSSensitiveDetectorHitsCollection;

extern G4ThreadLocal G4Allocator<LSSensitiveDetectorHit>* LSSensitiveDetectorHitAllocator;

inline void* LSSensitiveDetectorHit::operator new(size_t) {
  if(!LSSensitiveDetectorHitAllocator) LSSensitiveDetectorHitAllocator = new G4Allocator<LSSensitiveDetectorHit>;
  return (void *) LSSensitiveDetectorHitAllocator->MallocSingle();
}

inline void LSSensitiveDetectorHit::operator delete(void *hit) {
  LSSensitiveDetectorHitAllocator->FreeSingle((LSSensitiveDetectorHit*) hit);
}

#endif
