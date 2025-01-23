#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();



        for (int i = 1; i < n; ++i) {
            int digit = s[i]-'0';
            int prev  = s[i-1]-'0';
            if((digit%2==0)==(prev%2==0)){
                if(digit<prev){
                    sort(s.begin()+(i-1),s.begin()+(i+1));
                    break;

                }
            }
        }
        return s;
    }
};