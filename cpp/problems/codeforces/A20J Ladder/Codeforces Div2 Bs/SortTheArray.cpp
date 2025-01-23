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

struct ds {
    bool inc = true;
    int dec = 0;
    int dec_start = 1;
    int inc_start = 1;

};

void solve() {
    int n;
    cin >> n;
    int arr[n + 2];
    arr[n + 1] = INT32_MAX;
    arr[0] = INT32_MIN;
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    ds d;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] > arr[i + 1]) {
            if (d.inc) {
                d.dec++;
                d.dec_start = i;
                d.inc = false;
            }
        } else {
            if (!d.inc) {
                d.inc_start = i;
                d.inc = true;
            }
        }
    }

    if (d.dec <= 1 && arr[d.dec_start - 1] < arr[d.inc_start] && arr[d.dec_start] < arr[d.inc_start + 1]) {
        cout << "yes" << '\n';
        cout << d.dec_start << ' ' << d.inc_start << '\n';
    }
    else cout << "no" << '\n';


}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}