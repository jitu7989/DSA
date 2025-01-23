#include <bits/stdc++.h>;

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using vc = vector<int>;

class DisjointSet {
public:
    DisjointSet(int n){
        parent.resize(n+1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
        parent[0] = 0;
    }

    void __union(int i,int j){
        int jp = find(j);
        int ip = find(i);
        if(jp<ip) parent[ip] = jp;
        else      parent[jp] = ip;

    }
    int find(int n){
        if(parent[n]==n) return n;
        return parent[n] = find(parent[n]);
    }
    bool find(int i,int j){
        return find(i) == find(j);
    }
private:
    vector<int> parent;
};

