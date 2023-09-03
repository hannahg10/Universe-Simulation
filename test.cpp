/*
 * Author: Hannah Guillen
 * Course: COMP 2040 011
 * Last updated: June 6, 2023
 * 
 * Copyright 2023 Hannah Guillen
 */
#include <fstream>
#include <cmath>
#define BOOST_TEST_MODULE NBodyTest
#include <boost/test/included/unit_test.hpp>
#include "Universe.hpp"
#include "CelestialBody.hpp"

// Test 1: Check Universe number of bodies
BOOST_AUTO_TEST_CASE(NBodyTestOne) {
    std::ifstream inputFile("planets.txt");
    Universe testUniverse;
    inputFile >> testUniverse;
    inputFile.close();

    BOOST_CHECK_EQUAL(testUniverse.countBodies(), 5);
    BOOST_CHECK_CLOSE(testUniverse.universeRadius(), 2.50e+11, 1e-9);
}

// Test 2: Check Universe x and y coordinates
BOOST_AUTO_TEST_CASE(NBodyTestTwo) {
    std::ifstream inputFile("planets.txt");
    Universe testUniverse;
    inputFile >> testUniverse;
    inputFile.close();

    std::shared_ptr<CelestialBody> testBody2 = testUniverse.accessBody(1);
    BOOST_CHECK_CLOSE(testBody2->retrieveX(), 2.2790e+11, 1e-9);
    BOOST_CHECK_CLOSE(testBody2->retrieveY(), 0.0000e+00, 1e-9);
}

// Test 3: Check Celestial Body x and y coordinates
BOOST_AUTO_TEST_CASE(NBodyTestThree) {
    std::ifstream inputFile("planets.txt");
    Universe testUniverse;
    inputFile >> testUniverse;
    inputFile.close();

    std::shared_ptr<CelestialBody> testBody1 = testUniverse.accessBody(0);
    BOOST_CHECK_CLOSE(testBody1->retrieveX(), 1.4960e+11, 1e-9);
    BOOST_CHECK_CLOSE(testBody1->retrieveY(), 0.0000e+00, 1e-9);
}

// Test 4: Validate the size of the celestial bodies list
BOOST_AUTO_TEST_CASE(NBodyTestFour) {
    std::ifstream inputFile("planets.txt");
    Universe testUniverse;
    inputFile >> testUniverse;
    inputFile.close();

    for (int i = 0; i < testUniverse.countBodies(); ++i) {
        BOOST_CHECK(testUniverse.accessBody(i) != nullptr);
    }
}
