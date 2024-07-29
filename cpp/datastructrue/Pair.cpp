#include <bits/stdc++.h>

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair() {
        // Initialize members in the member initialization list
        first = T1();
        second = T2();
    }

    // Parameterized constructor
    Pair(const T1 &t1, const T2 &t2) {
        // Initialize members in the member initialization list
        first = t1;
        second = t2;
    }

    // Copy constructor
    Pair(const Pair &other) {
        // Initialize members in the member initialization list
        first = other.first;
        second = other.second;
    }

    // Assignment operator
    Pair &operator=(const Pair &other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    // Equality operator
    bool operator==(const Pair &other) const {
        return (first == other.first) && (second == other.second);
    }

    // Not equal operator
    bool operator!=(const Pair &other) const {
        return !(*this == other);
    }
};

int main() {
    // Testing the Pair template
    Pair<int, double> p1(10, 3.14); // Parameterized constructor
    Pair<int, double> p2(20, 6.28);
    Pair<int, double> p3 = p1; // Copy constructor

    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;
    cout << "p3: " << p3.first << ", " << p3.second << endl;

    // Assignment operator
    p3 = p2;

    cout << "After assignment:" << endl;
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;
    cout << "p3: " << p3.first << ", " << p3.second << endl;

    // Equality operator
    if (p1 == p2) {
        cout << "p1 and p2 are equal." << endl;
    } else {
        cout << "p1 and p2 are not equal." << endl;
    }

    // Not equal operator
    if (p2 != p3) {
        cout << "p2 and p3 are not equal." << endl;
    } else {
        cout << "p2 and p3 are equal." << endl;
    }

    return 0;
}