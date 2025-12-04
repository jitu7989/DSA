#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> totalTrappedWater;
    int n,m;
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};

    void print(const vector<vector<int>> & heightMap) {
        cout << "============================\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << heightMap[i][j] << " ";
            }
            cout << '\n';
        }
        cout << "============================\n";
    }
    int sum() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += totalTrappedWater[i][j];
            }
        }
        return ans;
    }
    void init(const vector<vector<int>> & heightMap) {
        n = heightMap.size();
        m = heightMap[0].size();
        totalTrappedWater = vector<vector<int>>(n, vector<int>(m, -1));
        for (auto arr: totalTrappedWater) {
            totalTrappedWater.resize(m);
        }
        for (auto i=0; i<n; i++) {
            totalTrappedWater[i][0] = 0;
            totalTrappedWater[i][m-1] = 0;
        }
        for (auto i=0; i<m; i++) {
            totalTrappedWater[0][i] = 0;
            totalTrappedWater[n-1][i] = 0;
        }
    };

    void findTrappedWater(int i, int j, const vector<vector<int>> & heightMap) {

        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push( make_pair(-heightMap[i][j], make_pair(i, j)));

        for (int i=0; i<n; i++) {

        }


    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        init(heightMap);
        print(this->totalTrappedWater);
        for (int i=1; i<n-1; i++) {
            for (int j=1; j<m-1; j++) {
                findTrappedWater(i,j,heightMap);
            }
        }
        return sum();
    }
};

int main() {
    Solution s;
    vector<vector<int>> heightMap1 = {
        {12, 12, 12, 12},
        {12, 2,  2,  12},
        {12, 2,  2,  12},
        {12, 12, 12, 12}
    };
    cout << "Calling with Test Case 1 (Simple Bowl): " << s.trapRainWater(heightMap1) << endl;

    // Test Case 2: Irregular terrain with a valley
    vector<vector<int>> heightMap2 = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };
    cout << "Calling with Test Case 2 (Irregular Terrain): " << s.trapRainWater(heightMap2) << endl;

    // Test Case 3: A "leaky" wall where water should flow out
    vector<vector<int>> heightMap3 = {
        {5, 5, 5, 5, 5},
        {5, 2, 1, 2, 5},
        {5, 1, 0, 1, 1}, // The '1' at the end is a leak
        {5, 2, 1, 2, 5},
        {5, 5, 5, 5, 5}
    };
    cout << "Calling with Test Case 3 (Leaky Wall): " << s.trapRainWater(heightMap3) << endl;

    // Test Case 4: No water can be trapped (flat surface)
    vector<vector<int>> heightMap4 = {
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5}
    };
    cout << "Calling with Test Case 4 (Flat Surface): " << s.trapRainWater(heightMap4) << endl;

    // Test Case 5: A large pillar in the middle that displaces water
    vector<vector<int>> heightMap5 = {
        {10, 10, 10, 10, 10},
        {10, 2,  2,  2,  10},
        {10, 2,  20, 2,  10}, // High pillar in the center
        {10, 2,  2,  2,  10},
        {10, 10, 10, 10, 10}
    };
    cout << "Calling with Test Case 5 (Central Pillar): " << s.trapRainWater(heightMap5) << endl;

    // Test Case 6: Edge case - a grid too small to trap water
    vector<vector<int>> heightMap6 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    cout << "Calling with Test Case 6 (Small Grid): " << s.trapRainWater(heightMap6) << endl;

    // Test Case 7: Edge case - an empty grid
    vector<vector<int>> heightMap7 = {};
    cout << "Calling with Test Case 7 (Empty Grid): " << s.trapRainWater(heightMap7) << endl;


}