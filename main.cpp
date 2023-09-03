/*
 * Author: Hannah Guillen
 * Course: COMP 2040 011
 * Last updated: June 6, 2023
 * 
 * Copyright 2023 Hannah Guillen
 */

#include <iostream>
#include <string>
#include "Universe.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " T Δt\n";
    return 1;
  }

  double T = std::stod(argv[1]);  // total simulation time
  double dt = std::stod(argv[2]);  // time quantum

  // Create instance of the Universe class
  Universe cosmos(std::cin);

  sf::Texture backgroundTexture;
  sf::Sprite background;
  // Load the background image file
  if (!backgroundTexture.loadFromFile("background.jpg")) {
    std::cerr << "ERROR! Failed to load background file!\n";
    return -1;
  }

  background.setTexture(backgroundTexture);

  // Get dimensions of the window from the background texture
  auto windowDimensions = backgroundTexture.getSize();
  // Create the window for displaying the simulation
  sf::RenderWindow window(sf::VideoMode(windowDimensions.x, windowDimensions.y),
   "The Solar System!");

  double elapsed_time = 0.0;
  // Main loop
  while (window.isOpen() && elapsed_time < T) {
    sf::Event event;
    // Event processing loop
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Clear the window for new drawing
    window.clear();
    // Draw the background
    window.draw(background);

    // Fetch universe properties for scaling
    double R = cosmos.universeRadius();
    int N = cosmos.countBodies();

    // Loop through all celestial bodies in the universe
    for (int i = 0; i < N; i++) {
      auto body = cosmos.accessBody(i);

      // Scale body position to window size
      double display_x = windowDimensions.x * (R + body->retrieveX()) / (2 * R);
      double display_y = windowDimensions.y - windowDimensions.y *
       (R + body->retrieveY()) / (2 * R);  // flip the y-axis

      // Set the body's position
      body->updatePosition(display_x, display_y);
      window.draw(*body);
    }
    // Display all the drawn elements
    window.display();

    cosmos.step(dt);  // advance the simulation
    elapsed_time += dt;
  }

  // Print out final state of the universe
  std::cout << cosmos;

  return 0;
}
