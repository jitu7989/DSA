#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < arr.size(); ++i) {
            while(!stk.empty() && arr[stk.top()]>arr[i]) stk.pop();
            stk.push(i);
        }
        set<int> st;
        while(!stk.empty()){
            st.insert(arr[stk.top()]);
            stk.pop();
        }
        return st.size();
    }
};

int main(){
    Solution s;
    vector<int> a({4,2,2,1,1});
    s.maxChunksToSorted(a);
    return 0;
}