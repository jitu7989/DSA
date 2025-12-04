/*
* slow_io_reader.cpp
 *
 * This program reads integers from the generated file using standard,
 * unoptimized C++ I/O (cin).
 *
 * By default, C++ streams are synchronized with C-style I/O (printf, scanf),
 * which adds significant overhead.
 *
 * How to compile and run:
 * g++ slow_io_reader.cpp -o slow_reader -std=c++17
 * ./slow_reader
 */
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

int main() {
    const std::string filename = "large_data.txt";
    std::ifstream input_file(filename);

    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open " << filename << ". Please run the data generator first." << std::endl;
        return 1;
    }

    // Redirect std::cin to read from the file.
    std::streambuf* orig_cin = std::cin.rdbuf();
    std::cin.rdbuf(input_file.rdbuf());

    std::cout << "--- Testing Slow I/O ---" << std::endl;

    // --- SLOW I/O CODE ---
    // Standard cin is used without any optimizations.

    auto start = std::chrono::high_resolution_clock::now();

    int n;
    std::cin >> n; // Read the number of integers

    long long sum = 0; // Use long long to prevent overflow
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        sum += val;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_ms = end - start;

    std::cout << "Finished reading " << n << " integers." << std::endl;
    std::cout << "Total sum (for verification): " << sum << std::endl;
    std::cout << "Time taken: " << duration_ms.count() << " ms" << std::endl;
    std::cout << "------------------------" << std::endl;

    // Restore original cin buffer
    std::cin.rdbuf(orig_cin);
    input_file.close();

    return 0;
}
