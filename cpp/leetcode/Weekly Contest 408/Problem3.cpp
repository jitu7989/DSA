#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> prefix_ones(n + 1, 0);
        vector<int> prefix_zeros(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            prefix_ones[i] = prefix_ones[i - 1] + (s[i - 1] == '1' ? 1 : 0);
            prefix_zeros[i] = prefix_zeros[i - 1] + (s[i - 1] == '0' ? 1 : 0);
        }

        unordered_map<int, int> count_map;
        count_map[0] = 1; // To handle the case when the difference is zero initially
        int count = 0;

        for (int i = 1; i <= n; ++i) {
            int ones = prefix_ones[i];
            int zeros = prefix_zeros[i];
            int difference = ones - zeros * zeros;

            if (count_map.find(difference) != count_map.end()) {
                count += count_map[difference];
            }

            count_map[difference]++;
        }

        return count;
    }
};