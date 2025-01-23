#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<int,char>;
using vii = vector<ii>;
using vi  = vector<int>;
typedef set<int> si;
typedef map<string, int> msi;

#define INF 1000000000;

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


map<int,int> _log2;
/*

0 000
1 001
2 010
3 011
4 100
5 101

*/


vector<int> getNumberOfOneTill(int n){
    vector<int> arr(19);
    for (int i = 0; i < 19; ++i) {
        int cycleRange = (1<<(i+1));
        int eachBitCycleRange = 1<<i;

        int bits = (n+1)/cycleRange;
        bits*=eachBitCycleRange;

        int left_over = n-( ((n+1)/cycleRange)*cycleRange );
        if(left_over>=eachBitCycleRange){
            bits+=left_over-(eachBitCycleRange-1);
        }
        arr[i]=bits;
    }
    return arr;
}
void solve(){
    int l,r; cin >> l >> r;

    vector<int> la = getNumberOfOneTill(l-1);
    vector<int> ra = getNumberOfOneTill(r);

    int mx = 0;
    for (int i = 0; i < 19; ++i) {
        ra[i]-=la[i];
        mx = max(ra[i],mx);
    }
    int len = ((r-l)+1);
    cout << (len-mx) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < 19; ++i) {
        _log2.insert({(1<<i),i});
    }

    int t; cin >> t;
    while(t--) solve();
    return 0;
}