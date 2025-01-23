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

int MAX_N = 1e5 + 7;
vector<int> arr(MAX_N);


void arr_input(int n) {
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void solve() {
    int n, distinct = 0;
    cin >> n;
    arr_input(n);
    map<int, int> m;
    set<int> s;
    s.clear();
    for (int i = 0; i < n; i++) s.insert(arr[i]);
    distinct = s.size();

    int tail = 0, head = -1, ans = n, window_distinct = 0;
    while (tail < n) {
        int nextHead = head + 1;
        while (nextHead < n && (window_distinct < distinct)) {
            head++;
            nextHead++;
            m[arr[head]]++;
            if (m[arr[head]] == 1) window_distinct++;
        }
        if (window_distinct == distinct) ans = min(ans, head - tail + 1);

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            m[arr[tail]]--;
            if (m[arr[tail]] == 0) window_distinct--;
            tail++;
        }
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
