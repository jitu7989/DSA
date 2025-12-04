#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<ll,ll>;
using vii = vector<ii>;
using vi  = vector<int>;
typedef set<int> si;
typedef map<string, int> msi;
#define INF 1000000000;
#define F first
#define S second
#define mp make_pair

// Debug mode control
#define DEBUG 1  // Set to 1 to enable debugging, 0 to disable

// Debugger macros that check DEBUG flag
#define debarr(a,n) if(DEBUG){cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;}
#define debmat(mat,row,col) if(DEBUG){cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}}
#define pr(...) if(DEBUG){dbs(#__VA_ARGS__, __VA_ARGS__);}
#define debset(set) if(DEBUG){cerr<<#set<<" : [ "; for(auto x:set){cerr<<x<<" ";} cerr<<"]\n";}
#define debmap(map) if(DEBUG){cerr<<#map<<" : [ "; for(auto x:map){cerr<<"{"<<x.F<<":"<<x.S<<"} ";} cerr<<"]\n";}

// Stream operators for debugging
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << "{" << it.first << ":" << it.second << "} "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << "{" << it.first << ":" << it.second << "} "; return os << "]";}

// Debug helper functions
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {if(DEBUG){cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}}

// Utility function
ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }



    int dfs(int node,vector<vector<pair<int,int>>>& g,int parentNode,string& s ){
        int mx = 1;
        for(auto &neighbour:g[node]){
            if(parentNode==neighbour.F) continue;
            if(neighbour.S==-1 && s[node-1]==s[neighbour.F-1] )
                neighbour.S = 1+dfs(neighbour.F,g,node,s);
            else if(neighbour.S==-1){
                neighbour.S=1;
            }
            mx = max(mx,neighbour.S);
        }
        pr(node, mx);
        return mx;
    }
    
    int longestPath(string& s, vector<vector<int>>& edges) {
        
        int n = s.length();
        vector<vector< pair<int,int> >> g(n+1);
        for(auto e:edges){
            g[e[0]].push_back({e[1],-1});
            g[e[1]].push_back({e[0],-1});
        }

        vector<int> dist(n+1, -1);
        int mx = 0;
        for (int i = 1; i <=n; ++i){
            dist[i] = dfs(i,g,0,s);
            mx = max(dist[i],mx);
        }
        for (int i = 1; i <= n; ++i) {
            pr(i,g[i]);
        }

        for(auto &e:edges){
            if(s[e[0]-1]!=s[e[1]-1]){
                int a = dist[e[0]]+dist[e[1]];
                mx = max(a,mx);
            }
        }
        return mx;
    }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> arr = {
        {1,2},
        {2,3},
        {2,4},
        {2,5},
        {1,6},
        {4,7},
        {3,8},
        {7,9},
        {3,10},
        {7,11},
        {5,12}
    };
    string s= "BB";
    cout << longestPath(s, arr) << '\n';

    return 0;
}