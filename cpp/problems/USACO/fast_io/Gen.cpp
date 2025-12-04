/*
* data_generator.cpp
 *
 * This program generates a large text file containing random integers.
 * This file will serve as the input for our I/O speed comparison tests.
 *
 * How to compile and run:
 * g++ data_generator.cpp -o data_generator -std=c++17
 * ./data_generator
 *
 * This will create a file named "large_data.txt".
 */
#include <iostream>
#include <fstream>
#include <random>

int main() {
    // Number of integers to generate.
    // 10 million is a good number to clearly see the I/O difference.
    const int NUM_INTEGERS = 10000000;
    const std::string filename = "large_data.txt";

    std::cout << "Generating " << NUM_INTEGERS << " random integers to '" << filename << "'..." << std::endl;

    // Use a file stream for output.
    std::ofstream data_file(filename);

    // Check if the file was opened successfully.
    if (!data_file.is_open()) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return 1;
    }

    // Setup for random number generation.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 1'000'000'000);

    // Write the total number of integers as the first line.
    data_file << NUM_INTEGERS << "\n";

    // Generate and write the integers to the file.
    for (int i = 0; i < NUM_INTEGERS; ++i) {
        data_file << distrib(gen) << "\n";
    }

    data_file.close();
    std::cout << "Data generation complete." << std::endl;

    return 0;
}
