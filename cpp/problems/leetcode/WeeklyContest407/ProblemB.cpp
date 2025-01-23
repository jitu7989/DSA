#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = (int)nums.size();
        vector<ll> diff(n);
        for (int i = 0; i < n; ++i)  diff[i] = nums[i]-target[i];
        long long operations = 0;
        for (int i = 0; i < n; ++i) {
            if (diff[i] != 0) {
                int j = i;
                while (j < n && diff[j] != 0) {
                    diff[j] -= diff[i];
                    ++j;
                }
                operations += abs(diff[i]);
            }
        }

        return operations;
    }
};


int main(){

    Solution s;



    return 0;
}