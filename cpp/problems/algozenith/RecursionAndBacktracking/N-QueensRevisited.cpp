#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<ll,ll>;
using vii = vector<ii>;
using vi  = vector<int>;
typedef set<int> si;
typedef map<string, int> msi;

#define INF 1000000000;

//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr);
// to clear array of integers


//---- Debugger ---- //
int add_debugger = 0;
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
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


int n;
char board[14][14];
char queen[14];


int dx[] = {2,2,-2,-2, 1,1,-1,-1};
int dy[] = {1,-1,1,-1, 2,-2,2,-2};
bool check(int row, int col){
    if(board[row][col]=='*') 
        return false;  
    

    for (int a = 0; a < row; ++a) 
        if(queen[a]==col || (row-a==abs(col-queen[a])))
            return false;
    for (int i = 0; i < 8; ++i) {
        int x = row+dx[i];
        int y = col+dy[i];
        if( (x>=0 && y>=0 && x<n && y<n) && board[x][y]=='*' ) return false;
    }

    return true;
}
int solveChessBoard(int row){
    if(n==row) {
        return 1;
    }
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        
        if(check(row,i)){
            queen[row] = i;
            board[row][i] = '*';
            ans += solveChessBoard(row+1);
            queen[row] = -1;
            board[row][i] = '.';
        }


    }
    return ans;
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(queen,-1,sizeof queen);
    cin >> n;
    for(int i=0; i<14; i++)
        for(int j=0; j<14; j++)
            board[i][j] = '.';

    cout << solveChessBoard(0);

    return 0;
}