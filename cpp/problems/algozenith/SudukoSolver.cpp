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

const int N = 3;
const int NN = N*N;
int boardRow[NN];
int boardCol[NN];
int grid[N][N];
int board[NN][NN];


int getChoices(int row,int col){
    int placedNumbers = boardCol[col] | boardRow[row] | grid[row/N][col/N];
    int unPlacedNumbers = ((1<<(NN+1))-1)^placedNumbers;
    if(unPlacedNumbers&1) unPlacedNumbers^=1;
    return unPlacedNumbers;
}

void placeOnBoard(int ch,int row, int col){
    int place = (1<<ch);
    if(place&1) place^=1;
    boardRow[row] = boardRow[row]|place;
    boardCol[col] = boardCol[col]|place;
    grid[row/N][col/N] = grid[row/N][col/N]|place;
    board[row][col] = ch;
}

void unplaceOnBoard(int ch, int row, int col){
    int place = ~(1<<ch);
    boardRow[row] = boardRow[row]&place;
    boardCol[col] = boardCol[col]&place;
    grid[row/N][col/N] = grid[row/N][col/N]&place;
    board[row][col] = 0;
}

bool solve(int row,int col){
    if(col==NN){
        return solve(row+1,0);
    }
    if(row==NN){
        debmat(board,NN,NN);
        return false;
    }

    if(board[row][col]==0){
        int choices = getChoices(row,col);
        for (int i = 1; i <= NN; ++i) {
            if( choices&(1<<i) ){
                placeOnBoard(i,row,col);
                bool solved = solve(row,col+1);
                unplaceOnBoard(i,row,col);
                if(solved) return true;
            }
        }
    }
    else {
        return solve(row,col+1);
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < NN; ++i) {
        for (int j = 0; j < NN; ++j) {
            int temp = 0; cin >> temp;
            placeOnBoard(temp,i,j);
        }
    }
    solve(0,0);
    return 0;
}