#include <bits/stdc++.h>
using namespace std;

// (a&b) + (a|b)  = (a+b)
// (a**2)+(b**2)

class Solution {
public:
    long long ONE  = 1LL;
    long long check_count_of_set_bits(long long mid, int x) {

        long long score = 0;
        for (int i = x-1; i <= 60; i+=x) {
            long long total = (ONE<<(i+ONE));
            long long total_ones_in_periodicity = (ONE<<i);
            long long left = (total_ones_in_periodicity)*(mid/total);
            long long remaining = max(((mid%total)+ONE)-total_ones_in_periodicity,0LL);

            score += (left+remaining);

        }
        return score;
    };

    long long findMaximumNumber(long long k, int x) {

        long long low = 0, high = 1e15;
        long long ans = 0;

        while (low<=high) {
            long long mid = low+((high-low)/2L);
            if (check_count_of_set_bits(mid,x)<=k) {
                ans = mid;
                low = mid+ONE;
            }
            else {
                high = mid-ONE;
            }

        }
        return ans;
    }
};


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution s;
    int k,x; cin>> k>> x;
    cout << s.findMaximumNumber(k,x) << '\n';

    return 0;
}