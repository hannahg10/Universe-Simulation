# Universe Simulation
A program that loads and displays a physics simulation/animation of the universe.

## Description
This program simulates the motion of celestial bodies in a universe, using the SFML library for rendering. It reads data about these celestial bodies from a file, calculates their positions over time, and displays their movements in a graphical window, representing a simplified model of our solar system.

![Universe simulation in action!](https://github.com/hannahg10/universe_simulation/assets/58957601/bf5d71f1-81b5-464e-be01-32fab94a8833)


## Features
- The `CelestialBody` class represents a celestial body in a Universe. The `Universe` class represents a universe containing multiple celestial bodies.
- Each celestial body's position is updated based on its velocity and the elapsed time. It uses utilizes manual memory management rather than relying on smart pointers.The `CelestialBody` objects are created dynamically and stored in a vector owned by the `Universe` class.

## Viewing the Simulation
1. Compile the program (which requires the use of the SFML library). An executable named `NBody` will be created.
2. This program accepts two command-line arguments (*T* and *△t*), reading the universe file from `stdin`. It will stimulate the universe, starting at *t* = 0.0 and continuing as long as *t<T*.
3. In the command line, run the executable first followed by the time limit given, then read the data from the `planets.txt` file. For example, the command could be `./NBody 157788000.0 25000.0 < planets.txt`.
4. The universe simulation will run, showing the planets rotating around the sun. It will terminate once the simulation elapses beyond the time limit given.
5. Once the animation stops, the program will output the final state of the universe
