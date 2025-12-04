#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

void setup_fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    // --- FAST I/O CODE ---
    setup_fast_io();


    const std::string filename = "large_data.txt";
    std::ifstream input_file(filename);

    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open " << filename << ". Please run the data generator first." << std::endl;
        return 1;
    }



    std::cout << "--- Testing Fast I/O ---" << std::endl;


    // Redirect std::cin to read from the file.
    std::cin.rdbuf(input_file.rdbuf());




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

    input_file.close();

    return 0;
}
