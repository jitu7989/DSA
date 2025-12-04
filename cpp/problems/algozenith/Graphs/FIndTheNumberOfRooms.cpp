// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

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

//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr);
// to clear array of integers


//---- Debugger ---- //
int add_debugger = 0;
#define debarr(a,n) if(add_debugger) {cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;}
#define debmat(mat,row,col) if(add_debugger){cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}}
#define pr(...) if(add_debugger) {dbs(#__VA_ARGS__, __VA_ARGS__);}

template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}

template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}


int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int n,m; 
vector<vector<char>> board;
vector<vector<int>> visited;

void dfs(int i,int j){
	if(visited[i][j]) return;
	visited[i][j] = 1;

	for (int k = 0; k < 4; ++k){
		int ti = i+dx[k];
		int tj = j+dy[k];
		if(ti>=0 && tj>=0 && ti<n && tj<m && !visited[ti][tj] && board[ti][tj]=='.' ){
			dfs(ti,tj);
		}
	}
}

void solve(){
	cin >> n >> m;
	board.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; ++i){
		board[i].resize(m);
		visited[i].resize(m);
		fill(visited[i].begin(),visited[i].end(),false);
	}

	

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> board[i][j];
		}
	}

	int component =  0;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if(!visited[i][j] && board[i][j]=='.') {
				dfs(i,j);
				component++;
			}
		}
	}

	cout << component << '\n';
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int tc;
    // cin >> tc;
    // while(tc--) 
    	solve();

    return 0;
}
