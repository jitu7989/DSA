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
bool screen[3][3];

int dx[] = {-1,-1,-1,  1,1, 1, 0, 0, 2, 2, -2,-2, 1,-1, 1,-1};
int dy[] = {-1, 0, 1, -1,0,-1, 1,-1, 1,-1,  1,-1, 2, 2,-2,-2};

vector<ii> posi;
int mod = 1e9 + 7;

ll generatePatterns(int row, int col){

    
    n--;
    screen[row][col] = true;
    posi.push_back({row,col});

    ll ans = (n<=0);

    if(n>0){
        int size = sizeof dx/4;
        for (int i = 0; i < size; i++){
            int x = row+dx[i], y = col+dy[i];
            while(x>=0 && x<3 && y>=0 && y<3){
                if(!screen[x][y]){
                    ans += generatePatterns(x,y);
                    break;
                }
                x += dx[i], y += dy[i];
            }
        }
    }
    screen[row][col] = false;
    n++;
    posi.pop_back();
    return ans;
}




signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ans += generatePatterns(i,j);
    
    cout << ans;
    return 0;
}

// 0 0 0
// 0 0 0
// 0 0 0

// 0 0 -> 5
// 2 2 -> 5
// 0 2 -> 5
// 2 0 -> 5

// 0 1 -> 7
// 1 0 -> 7
// 1 2 -> 7
// 2 1 -> 7

// 1 1 -> 8