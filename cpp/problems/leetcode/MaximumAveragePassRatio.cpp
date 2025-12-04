#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using dii = pair<double, ii>;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<dii> pq;
        for (int i = 0; i < classes.size(); i++) {
            int a = classes[i][0];
            int b = classes[i][1];
            pq.push({(-((double)a/(double)b)),{a,b}});
        }

        while (extraStudents--) {
            auto t = pq.top();
            if (t.second.first+1<=t.second.second) {
                pq.pop();
                t.second.first += 1;
                t.second.second += 1;
                t.first = -((double)t.second.first/(double)t.second.second);
                pq.push(t);
            }
        }

        double ans = 0;
        while (!pq.empty()) {
            auto t = pq.top();
            ans += -(t.first);
            pq.pop();
        }
        ans /= (double)classes.size();
        return ans;
    }
};
int main() {
    // [[1,2],[3,5],[2,2]]
    vector<vector<int>> testCases = {{1,2},{3,5},{2,2}};
    Solution s;
    s.maxAverageRatio(testCases, 2);
}