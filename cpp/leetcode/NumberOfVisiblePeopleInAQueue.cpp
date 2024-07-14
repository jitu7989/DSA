#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        stack<int> stk;
        vector ans(n,0);

        for (int i = n-1; i >= 0; i--) {
            int count = 0;
            while(!stk.empty() && heights[i]>=heights[stk.top()]) {
                count++;
                stk.pop();
            }
            ans[i]=count+(stk.empty()?0:1);
            stk.push(i);
        }
        return ans;
    }
};