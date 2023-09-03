/*
 * Author: Hannah Guillen
 * Course: COMP 2040 011
 * Last updated: June 6, 2023
 * 
 * Copyright 2023 Hannah Guillen
 */
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Universe.hpp"

Universe::Universe(istream &input) {
  // assuming the input format as you mentioned in your previous posts
  int numBodies;
  input >> numBodies >> radius;

  for (int i = 0; i < numBodies; i++) {
    double x, y, vel_x, vel_y, mass;
    std::string filePath;
    input >> x >> y >> vel_x >> vel_y >> mass >> filePath;
    celBodyList.push_back(std::make_shared<CelestialBody>
     (x, y, vel_x, vel_y, mass, filePath));
  }
}

void Universe::calculateForces() {
  for (auto &body1 : celBodyList) {
    for (auto &body2 : celBodyList) {
      if (body1 != body2) {
        body1->addForceFrom(*body2);
      }
    }
  }
}

void Universe::step(double seconds) {
  calculateForces();
  for (auto &body : celBodyList) {
    body->updateVelocity(seconds);
    body->step(seconds);
  }
}

void Universe::draw(sf::RenderTarget &target, sf::RenderStates state) const {
  for (const auto &body : celBodyList) {
    target.draw(*body, state);
  }
}

double Universe::universeRadius() const {
  return radius;
}

std::shared_ptr<CelestialBody> Universe::accessBody(int index) const {
  if (index < 0 || index >= celBodyList.size()) {
    return nullptr;  // or throw an exception
  }
  return celBodyList[index];
}

std::ostream& operator<<(std::ostream& os, const Universe& univ) {
  // Print the number of bodies and the universe radius
  os << univ.celBodyList.size() << " " << univ.radius << "\n";
  // Print each celestial body
  for (const auto& cb : univ.celBodyList) {
    os << *cb;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Universe& univ) {
  // Read the number of bodies and the universe radius
  int numBodies;
  is >> numBodies >> univ.radius;
  // Read each celestial body
  for (int i = 0; i < numBodies; i++) {
    auto cb = std::make_shared<CelestialBody>();
    is >> *cb;
    univ.celBodyList.push_back(std::move(cb));
  }
  return is;
}

int Universe::countBodies() const {
    return celBodyList.size();
}

