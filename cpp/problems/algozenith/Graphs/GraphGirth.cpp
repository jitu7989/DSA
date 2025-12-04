#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<int,int>;
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


int n,m;
int mn = 1e9;
vector<vector<int>> g;
vector<int> dis;


void bfs(int start){
    queue<int> q;
    q.push(start);
    dis[start] = 0;
    pr(start);
    while(!q.empty()){
        int node = q.front(); q.pop();
        pr(node, g[node]);
        for (int neighbour:g[node]) {
            if(dis[neighbour]==1e9){
                dis[neighbour] = dis[node]+1;
                q.push(neighbour);
            }
            else if(dis[node]<=dis[neighbour]){ // Not go back on parent node 
                mn = min(mn,dis[node]+dis[neighbour]+1);
                if (dis[node] == dis[neighbour]) return;  // for odd length cycles optimization
            }
        }
    }

}

void solve(){
    cin>>n>> m;
    g.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int a,b;cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    pr(n,m,g);
    for (int i = 1; i <= n; ++i) {
        dis.assign(n+1,1e9);
        bfs(i);
    }
    
    cout << (mn==1e9?-1:mn) << '\n';
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}