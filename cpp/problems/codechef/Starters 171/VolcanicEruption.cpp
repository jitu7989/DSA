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

#ifdef CUSTOM_BUILD
    #define DEBUG 1  
#else
    #define DEBUG 0  
#endif

// Debugger macros that check DEBUG flag
#define debarr(a,n) if(DEBUG){cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;}
#define debmat(mat,row,col) if(DEBUG){cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}}
#define pr(...) if(DEBUG){dbs(#__VA_ARGS__, __VA_ARGS__);}
#define debset(set) if(DEBUG){cerr<<#set<<" : [ "; for(auto x:set){cerr<<x<<" ";} cerr<<"]\n";} 
#define debmap(map) if(DEBUG){cerr<<#map<<" : [ "; for(auto x:map){cerr<<"{"<<x.F<<":"<<x.S<<"} ";} cerr<<"]\n";}

// Stream operators for debugging
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";} template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << "{" << it.first << ":" << it.second << "} "; return os << "]";}template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << "{" << it.first << ":" << it.second << "} "; return os << "]";}

// Debug helper functions 
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}template <class T> void prc(T a, T b) {if(DEBUG){cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}}

// Utility function
ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// TODO
void solve(){
    int n,p; cin >> n >> p;
    int arr[n]; for (int i = 0; i < n; ++i) cin >> arr[i];
    int protectionFromLeft[n],protectionFromRight[n], effectiveProtection[n];
    int maximum = 1e9+10;
    int mx = 0;
    int volcano_found = 0;

    for (int i = 0; i < n; ++i){
        if(arr[i]==0) {
            volcano_found=1;
            mx = 0;
        }
        if(volcano_found){
            protectionFromLeft[i] = max(mx,arr[i]);
            mx = protectionFromLeft[i];
        }
        else {
            protectionFromLeft[i] = -1;
        }
        
    }
    
    mx = 0;
    volcano_found = 0;
    
    for (int i = n-1; i>=0; i--){
        if(arr[i]==0) {
            volcano_found=1;
            mx = 0;
        }

        if(volcano_found){
            protectionFromRight[i] = max(mx,arr[i]);
            mx = protectionFromRight[i];
        }
        else {
            protectionFromRight[i] = -1;
        }
        
    }
    for (int i = 0; i < n; ++i){
        int mxx = max(protectionFromLeft[i],protectionFromRight[i]);
        int mnn = min(protectionFromLeft[i],protectionFromRight[i]);
        pr(i,mnn,mxx);
        if(mnn==-1) effectiveProtection[i] = mxx;
        else effectiveProtection[i] = mnn;
    }
    debarr(protectionFromLeft,n);
    debarr(protectionFromRight,n);
    debarr(effectiveProtection,n);
    for (int i = 0; i < n; ++i) {
        if(arr[i] == 0) cout << "0 ";
        else cout << (int)ceil((double)effectiveProtection[i]/(double)p) << ' ';
    }
    cout << '\n';
    if(DEBUG)cerr<<"=======================\n";
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) 
        solve();

    return 0;
}