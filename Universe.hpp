/*
 * Author: Hannah Guillen
 * Course: COMP 2040 011
 * Last updated: June 26, 2023
 * 
 * Copyright 2023 Hannah Guillen
 */
#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

#include <istream>
#include <memory>
#include <vector>
#include <string>
#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>

using std::istream;
using std::shared_ptr;
using std::vector;

class Universe {
 public:
  Universe() : radius(0.0) {}
  explicit Universe(std::istream &input);

  void calculateForces();
  void step(double seconds);
  void draw(sf::RenderTarget &target, sf::RenderStates state) const;

  double universeRadius() const;
  std::shared_ptr<CelestialBody> accessBody(int index) const;
  int countBodies() const;

  // Overload the << and >> operators for Universe
  friend std::ostream& operator<<(std::ostream& os, const Universe& univ);
  friend std::istream& operator>>(std::istream& is, Universe& univ);

 private:
  double radius;
  std::vector<std::shared_ptr<CelestialBody>> celBodyList;
};

#endif  // UNIVERSE_HPP
