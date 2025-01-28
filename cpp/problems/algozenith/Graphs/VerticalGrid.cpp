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
#define DEBUG 0  // Set to 1 to enable debugging, 0 to disable

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


int n,k;
vector<vector<int>> g;
int visited[110][10];
int dx[] = { 0, 0, 1,-1};
int dy[] = {-1, 1, 0, 0};

void proccessFall(){
    for (int col = 0; col < 10; col++) {
        int found_top=-1; 

        for (int row=n-1; row>=0; row--) {
            if(g[row][col]==0 && found_top==-1){
                found_top = row;
            }
            
            if(g[row][col]!=0 && found_top!=-1){
                g[found_top][col] = g[row][col];
                g[row][col] = 0;
                found_top--;
            }
            pr(row,col,found_top);

        }
    }
}



int  proccessPop(){
    int poppedAny = false;
    memset(visited,0,sizeof(visited));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            
            if(!visited[i][j] && g[i][j] ){
                
                vector<ii> componentNodes;
                queue<ii> q;
                visited[i][j] = 1;
                q.push(mp(i,j));

                int color = g[i][j];
                while(!q.empty()){
                    ii node = q.front(); q.pop();
                    componentNodes.push_back(node);
                    for (int i = 0; i < 4; ++i) {
                        int tx = node.F+dx[i];
                        int ty = node.S+dy[i];
                        if(tx<0 || ty<0 ||  tx>=n || ty>=10) continue;

                        if(!visited[tx][ty] && g[tx][ty]==color){
                            visited[tx][ty] = 1;
                            q.push(mp(tx,ty));
                        }
                    }
                }

                // pop cells
                if(componentNodes.size()>=k){
                    poppedAny = 1;
                    for(auto node:componentNodes){
                        g[node.F][node.S] = 0;
                    }
                }


            }

        }
    }

    return poppedAny;

}
void printGraph(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << g[i][j];
        }
        cout << '\n';
    }
}

void solve(){
    cin>>n>>k;

    g.resize(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        g[i].resize(10);
        for (int j = 0; j < 10; ++j) {
            g[i][j] = s[j]-'0';
        }
    }
    pr(n,k,g);
    proccessFall();

    while(proccessPop()){
        proccessFall();
    }

    printGraph();
}
signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    solve();

    return 0;
}