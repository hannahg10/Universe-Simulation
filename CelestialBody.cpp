/*
 * Author: Hannah Guillen
 * Course: COMP 2040 011
 * Last updated: June 6, 2023
 * 
 * Copyright 2023 Hannah Guillen
 */

#include <iostream>
#include <cmath>
#include "CelestialBody.hpp"

CelestialBody::CelestialBody(double init_x, double init_y, double vel_x,
 double vel_y, double body_mass, std::string file)
    : x(init_x), y(init_y), velocity_x(vel_x), velocity_y(vel_y),
     mass(body_mass), filePath(file), force_x(0), force_y(0) {
  if (!filePath.empty() && !bodyImage.loadFromFile(filePath)) {
    std::cerr << "Failed to read file.\n";
    std::exit(-1);
  }
  if (!filePath.empty()) {
    bodyTexture.loadFromImage(bodyImage);
    bodySprite.setTexture(bodyTexture);
  }
}

double CelestialBody::retrieveX() const { return x; }
double CelestialBody::retrieveY() const { return y; }
double CelestialBody::getMass() const { return mass; }

void CelestialBody::updatePosition(float newX, float newY) {
    bodySprite.setPosition(newX, newY);
}

void CelestialBody::addForceFrom(const CelestialBody& other) {
  double dx = other.x - x;
  double dy = other.y - y;
  double distance = std::sqrt(dx*dx + dy*dy);
  double force = G * mass * other.mass / (distance*distance*distance);
  force_x += force * dx;
  force_y += force * dy;
}

void CelestialBody::updateVelocity(double seconds) {
  velocity_x += seconds * force_x / mass;
  velocity_y += seconds * force_y / mass;
  // reset forces
  force_x = 0.0;
  force_y = 0.0;
}

void CelestialBody::step(double seconds) {
  x += seconds * velocity_x;
  y += seconds * velocity_y;
}

void CelestialBody::draw(sf::RenderTarget &target, sf::RenderStates state)
const {
  target.draw(bodySprite, state);
}

std::ostream& operator<<(std::ostream& os, const CelestialBody& b) {
    os << b.x << ' ' << b.y << ' ' << b.velocity_x << ' ' << b.velocity_y << ' '
       << b.mass << ' ' << b.filePath;
    return os;
}

std::istream& operator>>(std::istream& is, CelestialBody& b) {
    is >> b.x >> b.y >> b.velocity_x >> b.velocity_y >> b.mass >> b.filePath;
    if (!b.filePath.empty() && !b.bodyImage.loadFromFile(b.filePath)) {
        std::cerr << "Failed to read file.\n";
        std::exit(-1);
    }
    if (!b.filePath.empty()) {
        b.bodyTexture.loadFromImage(b.bodyImage);
        b.bodySprite.setTexture(b.bodyTexture);
    }
    return is;
}
