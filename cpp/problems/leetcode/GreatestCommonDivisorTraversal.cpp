#include "bits/stdc++.h"

using namespace std;
using ll = int;
using ii = pair<ll, ll>;


const int SEIVE_SIZE = 1e5 + 1;



class DisjointSet {
private:
    vector<int> parent;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    void merge(int i, int j){
        int jp = find(j);
        int ip = find(i);
        if(jp<ip) {
            parent[ip] = jp;
        }
        else {
            parent[jp] = ip;
        }
    }
    int find(int n){
        if(parent[n]==n) return n;
        return parent[n] = find(parent[n]);
    }
    bool find(int i,int j){
        return find(i) == find(j);
    }
};



class Solution {
public:


    static unordered_set<ll> get_factors(ll x) {
        unordered_set<ll> ans;
        ans.insert(x);
        for (ll i = 2; i * i <= x; ++i) {
            if (!(x % i)) {
                int cnt = 0;
                while (!(x % i)) {
                    cnt++;
                    x /= i;
                    if(x!=1) ans.insert(x);
                }
                ans.insert(i);
            }
        }
        return ans;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        DisjointSet set(SEIVE_SIZE);
        unordered_map<ll,unordered_set<ll>> factors;
        unordered_map<ll,unordered_set<ll>> factors_multiples;

        if(nums.size()==1) return true;
        for (int num : nums) {
            if(num==1) return false;
            if (factors.find(num) == factors.end()) {
                factors.insert(make_pair(num,get_factors(num)));
            }
        }
        for (const auto &item: factors){
            for (auto value: item.second){
                if(factors_multiples.find(value)==factors_multiples.end()){
                    unordered_set<ll> a;
                    factors_multiples.insert(make_pair(value,a));
                }
                factors_multiples.find(value)->second.insert(item.first);
            }
        }

        for (const auto& item: factors_multiples){
            unordered_set<ll> curr =  item.second;
            ll f = -1;
            for (const auto value: curr){
                if(f==-1){
                    f=value;
                }
                else{
                    set.merge(f,value);
                }
            }
        }

        int f = set.find(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if(!set.find(f,nums[i])) return false;
        }
        return true;

    }
};

ll main(){
    Solution a;
//    vector<int> vec({50,49,15,7,14,42,33,15,5,21,44,40});
//    vector<ll> vec({2,3,6});
    vector<ll> vec({51,46,4,3,48,9,49,7,54});
    a.canTraverseAllPairs(vec);
    return 0;
}