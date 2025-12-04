#include <bits/stdc++.h>;
#include <iostream>
#include <vector>
using namespace std;
struct Cuboid {
    // Minimum and maximum coordinates for each dimension
    std::vector<double> min, max;

    // Constructor
    Cuboid(double x1, double y1, double z1, double x2, double y2, double z2) {
        min = {x1, y1, z1};
        max = {x2, y2, z2};

        // Ensure min <= max for all dimensions
        for (int i = 0; i < 3; ++i) {
            if (min[i] > max[i]) {
                std::swap(min[i], max[i]);
            }
        }
    }

    // Check if a point lies within the cuboid (inclusive of boundaries)
    bool containsPoint(double x, double y, double z) const {
        return (min[0] <= x && x <= max[0]) &&
               (min[1] <= y && y <= max[1]) &&
               (min[2] <= z && z <= max[2]);
    }
};

// Check for overlap between two rectangles in 2D (projections)
bool rectanglesOverlap(double min1, double max1, double min2, double max2) {
    return min1 <= max2 && min2 <= max1;
}

// Check if two cuboids intersect in 3D space
bool cuboidsIntersect(const Cuboid& cuboid1, const Cuboid& cuboid2) {
    // Check for no intersection in each projected plane (xy, yz, zx)
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;
        if (!rectanglesOverlap(cuboid1.min[i], cuboid1.max[i], cuboid2.min[i], cuboid2.max[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    Cuboid cuboid1(a, b, c, d, e, f);
    Cuboid cuboid2(g, h, i, j, k, l);

    if (cuboidsIntersect(cuboid1, cuboid2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
