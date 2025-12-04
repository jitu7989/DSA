#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using ii = pair<ll, ll>;

using vii = vector<ii>;

using vi = vector<int>;

typedef set<int> si;

typedef map<string, int> msi;

#define INF 1000000000;

#define F first

#define S second

#define mp make_pair


#define DEBUG 1


#define debarr(a,n) if(DEBUG){cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;}

#define debmat(mat,row,col) if(DEBUG){cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}}

#define pr(...) if(DEBUG){dbs(#__VA_ARGS__, __VA_ARGS__);}

#define debset(set) if(DEBUG){cerr<<#set<<" : [ "; for(auto x:set){cerr<<x<<" ";} cerr<<"]\n";}

#define debmap(map) if(DEBUG){cerr<<#map<<" : [ "; for(auto x:map){cerr<<"{"<<x.F<<":"<<x.S<<"} ";} cerr<<"]\n";}


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
    for (auto &it: p) os << "{" << it.first << ":" << it.second << "} ";
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
    for (auto &it: p) os << "{" << it.first << ":" << it.second << "} ";
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
    if (DEBUG) {
        cerr << "[";
        for (T i = a; i != b; ++i) {
            if (i != a) cerr << ", ";
            cerr << *i;
        }
        cerr << "]\n";
    }
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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int range(int i, int n) { return 0 <= i && i <= n; }

/*

====================================COMMENT FOR PROBLEM UNDERSTANDING====================================



====================================xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx====================================

*/

void solve() {
    int n;

    cin >> n;

    int a[n];


    for (int i = 0; i < n; i++) cin >> a[i];


    int i = 2;

    while (i < 100000) {
        for (int el: a) {
            if (1 == gcd(el, i)) {
                cout << i << '\n';

                return;
            }
        }

        i++;
    }
}


signed main() {
    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);


    int tc;

    cin >> tc;

    while (tc--)

        solve();


    return 0;
}
