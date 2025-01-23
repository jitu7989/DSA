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
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
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



ll n,q;
// ll max_length = (1e5*5+2);
ll max_length = 15;
vector<pair<ll,ll>> a(max_length);
vector<ll> b(max_length);

vector<vector<ll>> finl(2,vector<ll>(max_length));


ll mod = 998244353;

bool compare(pair<ll,ll> a1,pair<ll,ll> a2){
    return a1.second<a2.second;
}
void solve(){
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i){
        a[i].first = i;
        cin >> a[i].second;
    }
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(b.begin(),b.begin()+(n+1));
    sort(a.begin(),a.begin()+(n+1),compare);
    ll product = 1LL;
    for (int i = 1; i <= n; ++i) {
        pair<ll,ll> p = a[i];
        finl[0][p.first] = p.second;
        finl[1][p.first] = b[i];
        product = (product*min(finl[0][p.first],finl[1][p.first]))%mod;
    }
    
    pr(finl[0]);
    pr(finl[1]);
    cerr << "Starting Queries\n";

    cout << product <<  ' ';
    while(q--){
        int a,x; cin >> a >> x;
        a--;
        ll snapshot = min(finl[0][x],finl[1][x]);
        finl[a][x]++;
        pr(finl[0]);
        pr(finl[1]);
        if(snapshot<min(finl[0][x],finl[1][x])){
            product /= snapshot;
            product = (product*(snapshot+1))%mod;
        }
        cout << product << ' ';
    }
    cout << '\n';
    cerr << "=====================\n";

}


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--) solve();

    return 0;
}
// 2 1 3 
// 1 2 4

// 2 1 3