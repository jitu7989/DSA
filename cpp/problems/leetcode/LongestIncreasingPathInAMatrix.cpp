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


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool comp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
		return b.F<a.F;
}

class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	
    	vector<pair<int,pair<int,int>>> g;
    	vector<vector<int>> dist(matrix.size(),vector<int>(matrix[0].size(),-1));
    	for (int i = 0; i < matrix.size(); ++i){
    		for (int j = 0; j < matrix[i].size(); j++){
    			g.push_back(make_pair(matrix[i][j],make_pair(i,j)));
    		}
    	}
    	sort(g.begin(),g.end(),comp);
    	pr(g);
    	int ans = 1;
    	for (auto a:g) {
    		int mx = 1;
    		for (int i = 0; i < 4; ++i){
    			int tx = a.S.F+dx[i];
    			int ty = a.S.S+dy[i];
    			if(tx<0 || tx>=matrix.size() || ty<0 || ty >= matrix[0].size()){
    				continue;
    			}
    			if(a.F<matrix[tx][ty]) mx = max(mx, 1+dist[tx][ty]);
    		}
    		dist[a.S.F][a.S.S] = mx;
    		ans = max(ans,dist[a.S.F][a.S.S]);
    		pr(a,dist);
    	}

    	return ans;
    }
};

int main(){

	vector<vector<int>> matrix1 = {{9,9,4},{6,6,8},{2,1,1}};
	Solution s;
	cout << s.longestIncreasingPath(matrix1) << '\n';
}