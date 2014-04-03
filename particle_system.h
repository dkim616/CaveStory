#ifndef PARTICLE_SYSTEM_H_
#define PARTICLE_SYSTEM_H_

#include <set>

#include <boost/shared_ptr.hpp>

#include "units.h"

struct Graphics;
struct Particle;

struct ParticleSystem {
  void addNewParticle(boost::shared_ptr<Particle> particle) {
    particles_.insert(particle);
  }
  void update(units::MS elapsed_time);
  void draw(Graphics& graphics);

private:
  typedef std::set<boost::shared_ptr<Particle>> ParticleSet;
  ParticleSet particles_;
};

struct ParticleTools {
  ParticleSystem& front_system;
  ParticleSystem& entity_system;
  Graphics& graphics;
};

#endif // PARTICLE_SYSTEM_H_
