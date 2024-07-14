int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int l[n],r[n];
        stack<int> ls,rs;
        fill(l,l+n,-1);
        fill(r,r+n,n);

        for (int i = 0, j= n-1; i < n; ++i,--j) {
            while(!ls.empty() && nums[ls.top()]>=nums[i] ) ls.pop();
            while(!rs.empty() && nums[rs.top()]>=nums[j] ) rs.pop();
            if(!ls.empty()) l[i] = ls.top();
            if(!rs.empty()) r[j] = rs.top();
            ls.push(i);
            rs.push(j);
        }

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if( (l[i]+1)<=k && k<=(r[i]-1) )
                mx = max(nums[i]*(r[i]-(l[i]+1)),mx);
        }
        return mx;
    }
};

int main(){
    Solution s;
    vector v({1,4,3,7,4,5});
    s.maximumScore(v,3);
    return 0;
};