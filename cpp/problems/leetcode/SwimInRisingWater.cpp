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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        dist.assign(n,vector<int>(m,1e9));
        priority_queue<pair<int,ii>> q; 
        q.push(mp(-grid[0][0],mp(0,0)));

        dist[0][0] = grid[0][0];

        while(!q.empty()){
            auto el = q.top(); q.pop();

            int efforts = -el.F;
            ii node = el.S;

            for (int i = 0; i < 4; ++i){
                int tx = node.F+dx[i];
                int ty = node.S+dy[i];
                if(tx<0 || ty<0 || tx>=n || ty>=m) continue;
                int updated_efforts = max((grid[tx][ty]==1e9?0:grid[tx][ty]), efforts);
                if(tx==n-1 && ty==m-2 && DEBUG)  {

                    pr(tx,ty,updated_efforts,el);
                    cerr << "=====================================\n";
                }
                if(updated_efforts<dist[tx][ty]){
                    dist[tx][ty]=updated_efforts;
                    q.push({-updated_efforts,{tx,ty}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};


int main(){
    Solution s;
    vector<vector<int>> grid1 = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    vector<vector<int>> grid2 = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    vector<vector<int>> grid3 = {{3,2},{0,1}};
    // cout<< s.swimInWater(grid1) << '\n';
    // cout<< s.swimInWater(grid2) << '\n';
    cout<< s.swimInWater(grid3) << '\n';
}