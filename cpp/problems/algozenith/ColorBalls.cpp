#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

//---- Debugger ---- //
#define debarr(a, n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat, row, col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)

template<class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")"; }

template<class T>
ostream &operator<<(ostream &os, const vector<T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class T>
ostream &operator<<(ostream &os, const multiset<T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class T>
void dbs(string str, T t) { cerr << str << " : " << t << "\n"; }

template<class T, class... S>
void dbs(string str, T t, S... s) {
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}

template<class T>
void prc(T a, T b) {
    cerr << "[";
    for (T i = a; i != b; ++i) {
        if (i != a) cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}

ll binpow(ll b, ll p, ll mod) {
    ll ans = 1;
    b %= mod;
    for (; p; p >>= 1) {
        if (p & 1)ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}



bool check(int k, int b,map<ll,int> &m){
    ll distinct_balls = 0;
    ll distinct_balls_required = b*k;
    for (const auto &item: m) distinct_balls+=min(b,item.second);
    return distinct_balls_required<=distinct_balls;
}
void solve() {

    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    map<ll,int> m;
    for (const auto &item: arr){
        auto it = m.find(item);
        int x = 0;
        if(it!=m.end()){
            x = it->second;
            it->second++;
        }
        else{
            m[item]=1;
        }
    }
    int lo=0, hi=n/k;
    int ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(k,mid,m)){
            ans = mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout << ans << '\n';
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