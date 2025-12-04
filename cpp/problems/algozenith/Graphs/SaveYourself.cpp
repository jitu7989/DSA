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
vector<vector<char>> board;
vector<vector<int>> dis;

int dx[]={ 0, 0, 1,-1};
int dy[]={-1, 1, 0, 0};


//TODO: IdentifySome Test Case is Failing for this problem hidden

void solve(){



    int n,m;
    cin>>n>>m;
    board.resize(n);
    dis.resize(n);
    for (int i = 0; i < n; ++i){
        board[i].resize(m);
        dis[i].resize(m);
        fill(dis[i].begin(), dis[i].end(), -1);
    }

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin >> board[i][j];

    queue<ii> q;
    ii person;
    // Adding All Monsters to Queue And locating person
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(board[i][j]=='M') {
                dis[i][j] = 0;
                q.push(mp(i,j));
            }
            else if(board[i][j]=='A'){
                person = mp(i,j);
            }
        }
    }

    while(!q.empty()){
        ii node = q.front(); q.pop();
        // Connected node add to q
        for (int choice = 0; choice < 4; choice++) {
            int tx=node.F+dx[choice];
            int ty=node.S+dy[choice];

            if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
            if(board[tx][ty]!='#' && dis[tx][ty]==-1) {
                dis[tx][ty] = dis[node.F][node.S]+1;
                q.push(mp(tx,ty));
            }
        }
    }


    q.push(person);
    dis[person.F][person.S] = 0;
    pr(board,dis);
    int exitFound = -1;
    while(!q.empty() && exitFound==-1){
        ii node = q.front(); q.pop();
        
        // Exit Found
        if(node.F==0 || node.S==0 || node.F==(n-1) || node.S==(m-1)){
            exitFound = dis[node.F][node.S];
            break;
        }
        // Connected node add to q
        for (int choice = 0; choice < 4; choice++) {
            int tx=node.F+dx[choice];
            int ty=node.S+dy[choice];
            if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
            
            int dist = dis[node.F][node.S]+1;

            if(board[tx][ty]!='#' && (dis[tx][ty]==-1 || dist<dis[tx][ty]) ) {
                dis[tx][ty] = dist;
                q.push(mp(tx,ty));
            }
        }
    }
    if(exitFound==-1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        cout << exitFound << '\n';
    }

}

/* 
-1 -1 -1 -1 -1
-1  0  1  2 -1  
-1  1 -1  1  0 
-1  0 -1  2  1
-1  1 -1 -1 -1
*/

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        solve();

    return 0;
}