#include <iostream>
#include <map>

// Helper function to print the map's contents
void print_map(const std::map<int, long long>& m) {
    std::cout << "Map Contents: { ";
    for (const auto& pair : m) {
        std::cout << pair.first << ":" << pair.second << " ";
    }
    std::cout << "}\n-------------------------------------\n";
}

// Helper function to test a key and print the results clearly
void test_key(const std::map<int, long long>& m, int key_to_find) {
    std::cout << ">>> Searching for key: " << key_to_find << std::endl;

    // --- Test lower_bound ---
    auto it_lower = m.lower_bound(key_to_find);

    std::cout << "  lower_bound(" << key_to_find << ") result: ";
    if (it_lower != m.end()) {
        // The iterator is valid, print what it points to
        std::cout << "Points to key " << it_lower->first << " (value: " << it_lower->second << ")\n";
    } else {
        // The iterator is at the end, meaning no key is >= key_to_find
        std::cout << "Points to map.end()\n";
    }

    // --- Test upper_bound ---
    auto it_upper = m.upper_bound(key_to_find);
    
    std::cout << "  upper_bound(" << key_to_find << ") result: ";
    if (it_upper != m.end()) {
        // The iterator is valid
        std::cout << "Points to key " << it_upper->first << " (value: " << it_upper->second << ")\n";
    } else {
        // The iterator is at the end, meaning no key is > key_to_find
        std::cout << "Points to map.end()\n";
    }
    std::cout << "-------------------------------------\n";
}


int main() {
    std::map<int, long long> my_map = {
        {10, 100LL},
        {20, 200LL},
        {30, 300LL},
        {50, 500LL},
        {60, 600LL}
    };

    print_map(my_map);

    // Case 1: Key exists in the map (30)
    // lower_bound should find the exact key.
    // upper_bound should find the next key after 30.
    test_key(my_map, 30);

    // Case 2: Key does NOT exist, but is between two keys (35)
    // lower_bound should find the first key >= 35 (which is 50).
    // upper_bound should find the first key > 35 (which is also 50).
    test_key(my_map, 35);
    
    // Case 3: Key is the first element (10)
    // lower_bound finds the exact key.
    // upper_bound finds the next key.
    test_key(my_map, 10);

    // Case 4: Key is smaller than any key in the map (5)
    // lower_bound should find the first element >= 5 (which is 10).
    // upper_bound should find the first element > 5 (which is also 10).
    test_key(my_map, 5);
    
    // Case 5: Key is the last element (60)
    // lower_bound finds the exact key.
    // upper_bound finds nothing greater, so it returns map.end().
    test_key(my_map, 60);

    // Case 6: Key is larger than any key in the map (70)
    // lower_bound finds nothing >= 70, returns map.end().
    // upper_bound finds nothing > 70, returns map.end().
    test_key(my_map, 70);

    return 0;
}