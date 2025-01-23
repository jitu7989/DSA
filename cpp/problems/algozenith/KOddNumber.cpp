#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using vii = vector<ii>;
using vi = vector<int>;
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

template<class S, class T>
ostream &operator <<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")"; }

template<class T>
ostream &operator <<(ostream &os, const vector<T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class T>
ostream &operator <<(ostream &os, const unordered_set<T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class S, class T>
ostream &operator <<(ostream &os, const unordered_map<S, T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class T>
ostream &operator <<(ostream &os, const set<T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class T>
ostream &operator <<(ostream &os, const multiset<T> &p) {
    os << "[ ";
    for (auto &it: p) os << it << " ";
    return os << "]";
}

template<class S, class T>
ostream &operator <<(ostream &os, const map<S, T> &p) {
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


void solve() {
    ll n, k, d;
    cin >> n >> k >> d;
    vector<ll> arr(n);
    vector<ll> prefix(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        prefix[i] = arr[i];
        if (i > 0) prefix[i] += prefix[i - 1];
    }
    multiset<ll> mt;
    ll tail = 0, head = -1;

    ll oddNumbers = 0;
    ll ans = -1e18;

    while (tail < n) {
        ll nextHead = head + 1;
        while (nextHead < n && ((arr[nextHead] & 1) == 0 || oddNumbers < k)) {

            oddNumbers += (arr[nextHead] & 1);
            mt.insert(prefix[nextHead]);

            head = nextHead;
            nextHead++;
        }

        ll base = (tail==0?0:prefix[tail-1]);
        auto it = mt.upper_bound(base+d);

        if (it!=mt.begin()) {
            it--;
            ans = max(ans, *it-base);
        }

        if (head < tail) {
            oddNumbers = 0;
            mt.clear();
            tail++;
            head = tail - 1;
        } else {
            oddNumbers -= (arr[tail] & 1);
            mt.erase(mt.find(prefix[tail]));
            tail++;
        }
    }
    if (ans == -1e18) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
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
