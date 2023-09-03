CC = g++
CFLAGS = -std=c++17 -Wall -Wextra
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework

DEPS = Universe.hpp CelestialBody.hpp
OBJECTS = Universe.o CelestialBody.o main.o
TEST_OBJECTS = Universe.o CelestialBody.o test.o
PROGRAM = NBody

.PHONY: all clean lint

all: $(PROGRAM) test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(SFMLFLAGS)

test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(SFMLFLAGS)

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(PROGRAM) test

lint:
	cpplint *.cpp *.hpp
