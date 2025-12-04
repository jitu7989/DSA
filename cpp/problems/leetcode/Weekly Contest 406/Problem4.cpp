#include <bits/stdc++.h>
using namespace std;

struct hash_tuple {
    template <class T1, class T2, class T3, class T4>
    size_t operator()(const tuple<T1, T2, T3, T4>& t) const {
        auto hash1 = hash<T1>()(get<0>(t));
        auto hash2 = hash<T2>()(get<1>(t));
        auto hash3 = hash<T3>()(get<2>(t));
        auto hash4 = hash<T4>()(get<3>(t));
        return hash1 ^ hash2 ^ hash3 ^ hash4;
    }
};

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        horizontalCuts.push_back(0);
        horizontalCuts.push_back(m);
        verticalCuts.push_back(0);
        verticalCuts.push_back(n);

        // Sort the cuts
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        // Initialize the DP table
        unordered_map<tuple<int, int, int, int>, int, hash_tuple> dp;

        // Helper function for DP
        function<int(int, int, int, int)> dfs = [&](int h_start, int h_end, int v_start, int v_end) {
            auto key = make_tuple(h_start, h_end, v_start, v_end);
            if (dp.find(key) != dp.end()) {
                return dp[key];
            }

            int min_cost = INT_MAX;

            // Horizontal cuts
            for (int h = h_start + 1; h < h_end; ++h) {
                int cost = n + dfs(h_start, h, v_start, v_end) + dfs(h, h_end, v_start, v_end);
                min_cost = min(min_cost, cost);
            }

            // Vertical cuts
            for (int v = v_start + 1; v < v_end; ++v) {
                int cost = m + dfs(h_start, h_end, v_start, v) + dfs(h_start, h_end, v, v_end);
                min_cost = min(min_cost, cost);
            }

            if (min_cost == INT_MAX) {
                min_cost = 0;
            }

            dp[key] = min_cost;
            return min_cost;
        };

        return dfs(0, horizontalCuts.size() - 1, 0, verticalCuts.size() - 1);

    }
};