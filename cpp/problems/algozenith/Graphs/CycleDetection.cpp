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


int n,m;
vector<vector<int>> g;
vector<int> colour;
vector<int> parent;
vector<vector<int>> cycles;
vector<int> cntCycle;
vector<int> prefixOrder;

bool is_cycle = false;

void dfs(int node, int parentNode){
    colour[node] = 2;
    parent[node]=parentNode;
    if(DEBUG) cerr << "Started Call: "; 
    pr(node,colour);
    for (auto neigbour:g[node]) {
        if(colour[neigbour]==1){
            // Forward Edge visiting first time
            dfs(neigbour,node);
        }
        else if(colour[neigbour]==2){
            if(neigbour==parent[node]) continue;
            // Cycle is detected here backward edge found 
            vector<int> cycle;
            int temp = node;
            while(temp!=neigbour){
                cycle.push_back(temp);
                temp = parent[temp];
            }
            cycle.push_back(temp);
            reverse(cycle.begin(),cycle.end());
            cycles.push_back(cycle);
            cntCycle[node]++;
            cntCycle[parent[neigbour]]--;
            is_cycle = 1;
        }
        else if(colour[neigbour]==3){
            //  
        }
    }

    colour[node] = 3;
    prefixOrder.push_back(node);

    if(DEBUG) cerr << "Ending call: ";
    pr(node,colour);
}
// TODO: Edge cases
// Self Loop
// Multi edge
void solve(){
    int n,m;
    cin>>n>>m;
    g=vector<vector<int>>(n+1);
    colour=vector<int>(n+1,1);
    parent=vector<int>(n+1,0);
    cntCycle=vector<int>(n+1,0);

    for(int i=0;i<m;++i){
        int n1,n2;cin>>n1>>n2;
        
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }
    
    pr(g);
    for (int i = 1; i <= n; ++i){
        if(colour[i]==1) {
            if(DEBUG) cerr << "DFS Call on node: " << i << '\n';
            dfs(i,0);
        }
    }


    if(is_cycle) {
        cout << "Cycle Detected" << '\n';
        for (int num:prefixOrder){
            cntCycle[parent[num]]+=cntCycle[num];
        }


        cout << "All Cycles: \n";
        for(auto cycle:cycles){
            for(auto num:cycle) cout << num << " ";
            cout << '\n';
        }
        int cntNode = 0;
        cout << "Nodes part of cycles: ";
        for (int i = 1; i <= n; ++i){
            if(cntCycle[i]){
                cntNode++;
                cout << i << " ";
            }
        }
        cout << '\n';
        cout << "Number of Node part of all cycles: " << cntNode << '\n';
        for (int i = 1; i <= n; ++i){
            cout << i << " Node is part of " << cntCycle[i] << " cycles \n";
        }
    }
    else {
        cout << "No Cycle Detected" << '\n';
    }
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) 
        solve();

    return 0;
}