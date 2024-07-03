#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;



class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        sort(nums.begin(),nums.end());

        int len = nums.size();
        int mn = INT32_MAX;
        for (int i = 0,j=len-4; i <= 3; ++i,++j) {
            mn = min(nums[j]-nums[i],mn);
        }
        return mn;
    }
};