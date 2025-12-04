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

#define N 1002
int n,m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};




queue<pair<int, int> > monsterQ, personQ;
pair<int, int> parent[N][N];


#define DEB  if(DEBUG) cerr << "================================\n"; debmat(grid, n,m); debmat(distancePerson, n,m); debmat(distanceMonster, n,m); debmat(parent, n,m);
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    bool grid[n][m];
    int distancePerson[n][m];
    int distanceMonster[n][m];
    memset(grid, false, sizeof(grid));
    memset(distanceMonster, -1, sizeof(distanceMonster));
    memset( distancePerson, -1, sizeof(distancePerson));

    char c;
    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        for (int j = 0; j < m; ++j){
            c = s[j];
            grid[i][j] = true;
            if(c=='#'){
                grid[i][j] = false;
            }
            else if(c=='M'){
                monsterQ.push(mp(i,j));
                distanceMonster[i][j] = 0;
            }
            else if(c=='A'){
                personQ.push(mp(i,j));
                distancePerson[i][j] = 0;
                parent[i][j].first=parent[i][j].second=-1;
            }
        }
    }
    DEB
    
    while(!monsterQ.empty()){
        auto monster = monsterQ.front();
        monsterQ.pop();
        for (int i = 0; i < 4; ++i) {
            int tx=monster.F+dx[i];
            int ty=monster.S+dy[i];
            if(tx<0 || ty<0 || tx>=n || ty>=m) continue;
            if(grid[tx][ty] && distanceMonster[tx][ty]==-1) {
                monsterQ.push(mp(tx,ty));
                distanceMonster[tx][ty] = distanceMonster[monster.F][monster.S]+1;
            }
        }
    }
    while(!personQ.empty()){
        auto person = personQ.front();
        personQ.pop();
        for (int i = 0; i < 4; ++i) {
            int tx=person.F+dx[i];
            int ty=person.S+dy[i];
            if(tx<0 || ty<0 || tx>=n || ty>=m) continue;
            if(grid[tx][ty] && distancePerson[tx][ty]==-1) {
                personQ.push(mp(tx,ty));
                distancePerson[tx][ty] = distancePerson[person.F][person.S]+1;
            }
        }
    }

    // Iterate over boundry cell and check any cell exsist where person reached first 
    DEB

    int can_reach = 0;
    int distance = 1e9;

    for (int i = 0; i < n; ++i){
        int j1 = 0, j2 = m-1;
        if(grid[i][j1] && (distancePerson[i][j1]<distanceMonster[i][j1] || distanceMonster[i][j1]==-1)&& distancePerson[i][j1]!=-1 ){
            can_reach = 1;
            distance = min(distance,distancePerson[i][j1]);
        }
        pr(i,j1,j2);
        if(grid[i][j2] && (distancePerson[i][j2]<distanceMonster[i][j2] || distanceMonster[i][j2]==-1) && distancePerson[i][j2]!=-1 ){
            can_reach = 1;
            distance = min(distance,distancePerson[i][j2]);
        }
    }
    for (int i = 0; i < m; ++i){
        int j1 = 0, j2 = n-1;

        if(grid[j1][i] && (distancePerson[j1][i]<distanceMonster[j1][i] || distanceMonster[j1][i]==-1) && distancePerson[j1][i]!=-1 ){
            can_reach = 1;
            distance = min(distance,distancePerson[j1][i]);
        }


        if(grid[j2][i] && (distancePerson[j2][i]<distanceMonster[j2][i] || distanceMonster[j2][i]==-1) && distancePerson[j2][i]!=-1 ){
            can_reach = 1;
            distance = min(distance,distancePerson[j2][i]);
        }
    }
    if(can_reach){
        cout << "YES\n" << distance << '\n';
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
