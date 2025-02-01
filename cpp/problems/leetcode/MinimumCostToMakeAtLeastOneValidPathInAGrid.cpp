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

#ifdef CUSTOM_BUILD
    #define DEBUG 1  
#else
    #define DEBUG 0  
#endif

// Debugger macros that check DEBUG flag
#define debarr(a,n) if(DEBUG){cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a{i]<<" "; cerr<<endl;}
#define debmat(mat,row,col) if(DEBUG){cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat{i]{j]<<" ";cerr<<endl;}}
#define pr(...) if(DEBUG){dbs(#__VA_ARGS__, __VA_ARGS__);}
#define debset(set) if(DEBUG){cerr<<#set<<" : { "; for(auto x:set){cerr<<x<<" ";} cerr<<"]\n";} 
#define debmap(map) if(DEBUG){cerr<<#map<<" : [ "; for(auto x:map){cerr<<"{"<<x.F<<":"<<x.S<<"} ";} cerr<<"]\n";}

// Stream operators for debugging
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";} template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << "{" << it.first << ":" << it.second << "} "; return os << "]";}template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << "{" << it.first << ":" << it.second << "} "; return os << "]";}

// Debug helper functions 
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}template <class T> void prc(T a, T b) {if(DEBUG){cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}}

// Utility function
ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


int dx[]={ 0, 0, 1,-1};
int dy[]={ 1,-1, 0, 0};
vector<vector<int>> dist;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        dist.assign(n,vector<int>(m,1e9));

        deque<ii> q; q.push_back(mp(0,0));
        dist[0][0] = 0;

        while(!q.empty()){
            auto node = q.front(); q.pop_front();
            for (int i = 0; i < 4; ++i){
                int tx = node.F+dx[i];
                int ty = node.S+dy[i];
                
                if(tx<0 || ty<0 || tx>=n || ty>=m) continue;
                int cost = (i+1)!=grid[node.F][node.S];
                
                if(cost+dist[node.F][node.S]<dist[tx][ty]){
                    dist[tx][ty]=cost+dist[node.F][node.S];
                    if(cost) q.push_back({tx,ty});
                    else q.push_front({tx,ty});
                }
            }
        }
        pr(dist);
        return dist[n-1][m-1];
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid1 = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    vector<vector<int>> grid2 = {{2,2,2},{2,2,2}};
    cout<< s.minCost(grid1) << '\n';
    cout<< s.minCost(grid2) << '\n';
}