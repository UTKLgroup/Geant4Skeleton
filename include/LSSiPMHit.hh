#ifndef LSSiPMHit_h
#define LSSiPMHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleDefinition.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

class LSSiPMHit : public G4VHit {
public:
  LSSiPMHit();
  virtual ~LSSiPMHit();

  G4int operator==(const LSSiPMHit &right) const;
  inline void * operator new(size_t);
  inline void operator delete(void * aHit);

  virtual void Draw();
  virtual void Print();

private:
  G4double energy;
  G4ParticleDefinition * particle;

public:
  inline void SetEnergy(G4double ene) {
    energy = ene;
  }

  inline G4double GetEnergy() {
    return energy;
  }

  inline void SetParticle(G4ParticleDefinition * pdef) {
    particle = pdef;
  }

  inline G4ParticleDefinition * GetParticle() {
    return particle;
  }
};

typedef G4THitsCollection<LSSiPMHit> LSSiPMHitsCollection;

extern G4Allocator<LSSiPMHit> LSSiPMHitAllocator;

inline void * LSSiPMHit::operator new(size_t) {
  void *aHit;
  return (void *) LSSiPMHitAllocator.MallocSingle();
}

inline void LSSiPMHit::operator delete(void * aHit) {
  LSSiPMHitAllocator.FreeSingle((LSSiPMHit *) aHit);
}

#endif
