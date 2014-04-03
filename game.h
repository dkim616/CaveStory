#ifndef GAME_H_
#define GAME_H_

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

#include "units.h"
#include "damage_texts.h"
#include "particle_system.h"

struct Player;
struct Graphics;
struct Map;
struct FirstCaveBat;

struct Game {
  Game();
  ~Game();

  static units::Tile kScreenWidth;
  static units::Tile kScreenHeight;

private:
  void eventLoop();
  void update(units::MS elapsed_time_ms, Graphics& graphics);
  void draw(Graphics &graphics);

  boost::shared_ptr<Player> player_;
  boost::shared_ptr<FirstCaveBat> bat_;
  boost::scoped_ptr<Map> map_;

  ParticleSystem front_particle_system_;
  ParticleSystem entity_particle_system_;
  DamageTexts damage_texts_;

};

#endif // GAME_H_
