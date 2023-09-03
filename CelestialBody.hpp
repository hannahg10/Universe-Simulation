/*
 * Author: Hannah Guillen
 * Course: COMP 2040 011
 * Last updated: June 6, 2023
 * 
 * Copyright 2023 Hannah Guillen
 */

#ifndef CELESTIALBODY_HPP
#define CELESTIALBODY_HPP

#include <string>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable {
 public:
  CelestialBody(double init_x = 0, double init_y = 0, double vel_x = 0,
                double vel_y = 0, double body_mass = 0,
                std::string file = "");

  double retrieveX() const;
  double retrieveY() const;
  double getMass() const;
  void updatePosition(float newX, float newY);
  void addForceFrom(const CelestialBody& other);
  void updateVelocity(double seconds);
  void step(double seconds);

 private:
  sf::Image bodyImage;
  sf::Sprite bodySprite;
  sf::Texture bodyTexture;
  double x, y;
  double velocity_x, velocity_y;
  double mass;
  std::string filePath;
  double force_x, force_y;  // the net force acting on this body

  static constexpr double G = 6.67e-11;  // gravitational constant

  void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

  // Overload the << and >> operators
  friend std::ostream& operator<<(std::ostream& os, const CelestialBody& b);
  friend std::istream& operator>>(std::istream& is, CelestialBody& b);
};

#endif  // CELESTIALBODY_HPP
