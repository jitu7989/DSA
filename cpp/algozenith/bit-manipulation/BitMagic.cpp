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


ll poped_bits(ll x) {
    ll cnt = 0;
    while (x) {
        x &= x - 1;
        cnt++;
    }
    return cnt;
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    long long q;
    cin >> q;
    long long n = 0;
    ll one=1;
    while (q--) {
        ll qt, i;
        cin >> qt;
        if (qt == 1) {
            cin >> i; // test(i): Print 1 if ith flag is ON, otherwise 0.
            cout << ((n >> i) & one) << '\n';
        } else if (qt == 2) {
            cin >> i; // set(i): Set ith flag to ON
            n |= (one << i); // Turn On ith Bit
        } else if (qt == 3) {
            cin >> i;
            // Two Approaches
            // if ((n >> i) & 1) n = (n ^ (1 << i)); // Turn Off ith Bit
            n &= (~(one << i));
        } else if (qt == 4) {
            cin >> i;
            n ^= (one<<i);
        } else if (qt == 5) {
            cout << (poped_bits(n) == 60) << "\n"; // all ones
        } else if (qt == 6) {
            // any ones
            cout << (poped_bits(n)>0) << '\n';
        } else if (qt == 7) {
            cout << (n == 0) << '\n';
        } else if (qt == 8) {
            cout << poped_bits(n) << '\n';
        } else if (qt == 9) {
            cout << n << '\n';
        }
    }

    return 0;
}
