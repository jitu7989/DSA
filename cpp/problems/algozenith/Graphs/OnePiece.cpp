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
vector<vector<int>> board;
vector<vector<int>> dist;

int dx[]={ 0, 0, 1,-1};
int dy[]={ 1,-1, 0, 0};

int range(ii p){
    return p.F>=1 && p.S>=1 && p.F<=n && p.S<=m;
}

void solve(){

    cin>>n>>m;
    board.assign(n+1,vector<int>(m+1));
    dist.assign(n+1,vector<int>(m+1,1e9));
    for (int i=1;i<=n;++i){
        for (int j=1;j<= m;++j){
            cin >> board[i][j];
        }
    }

    deque<ii> q;
    q.push_back(mp(1,1));
    dist[1][1] = 0;
    
    while(!q.empty()){
        ii node = q.front(); q.pop_front();

        string s ="";
        if(DEBUG) s+="Node (" + to_string(node.F) +","+to_string(node.S)+") ";
        for (int i = 0; i < 4; ++i){
            ii neighbour = mp(node.F+dx[i] , node.S+dy[i]);
            if(!range(neighbour) ) continue;

            int cost = (i+1)!=board[node.F][node.S];

            if((dist[node.F][node.S]+cost)<dist[neighbour.F][neighbour.S] ){ // Takes Zero Cost 

                if(DEBUG) s+=" Neighbour Node (" + to_string(neighbour.F) +","+to_string(neighbour.S)+") ";

                if(cost) q.push_back(neighbour);
                else q.push_front(neighbour);

                dist[neighbour.F][neighbour.S] = (dist[node.F][node.S]+cost);
            }

        }
        if(DEBUG){
            for (auto x:q) cerr << x << " ";
            cerr << '\n';
            cerr << s << '\n';
        }
    }

    cout << dist[n][m];

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
