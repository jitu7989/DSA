// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

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


int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int row, int col,vector<vector<int>> &visited) {
    int n = visited.size(), m = visited[0].size();
    // Connected Node in Component
    if(visited[row][col]) return;

    vector<ii> ans;
    queue<ii> q;

    q.push(mp(row,col));
    visited[row][col] = 1;

    while (!q.empty()) {
        ii node = q.front(); q.pop();
        ans.push_back(node);


        pr(node);
        
        for (int k = 0; k < 4; ++k) {
            int ti = node.F + dx[k], tj = node.S + dy[k];
            pr(ti,tj);
            if (ti >= 0 && tj >= 0 && ti < n && tj < m ) {
                pr(!visited[ti][tj]);
                if(!visited[ti][tj]) {
                    q.push(mp(ti, tj));
                    visited[ti][tj] = 1;
                }

            }
        }
    }
    pr(row, col, ans);
    if (ans.size() > 1) {
        for (ii par: ans) {
            visited[par.F][par.S] = ans.size();
        }
    }
    else {
        visited[row][col] = 0;
    }
}

void printBoard(vector<vector<int>> &visited) {
    int n = visited.size(), m = visited[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}


void solve() {
    int n, m;cin >> n >> m;
	vector<vector<int>> board = vector<vector<int> >(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
            // Visiting Each Node if Node is 0 then explore
			bfs(i, j,board);
		}
	}
	printBoard(board);
}



signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) solve();

	return 0;
}

