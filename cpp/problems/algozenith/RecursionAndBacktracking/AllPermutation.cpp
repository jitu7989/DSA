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

int n;
int arr[9];
bool visited[9];
int permutation[9];

map<int,int> mp;

void genrate_all_permutation(int curr) {
    if (curr>=n) {
        for (int i = 0; i < n; ++i)cout << permutation[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            permutation[curr] = arr[i];
            visited[i] = true;
            genrate_all_permutation(curr+1);
            visited[i] = false;
        }
    }
}

void genrate_unique_permutation(int curr) {
    if (curr>=n) {
        for (int i = 0; i < n; ++i) cout << permutation[i] << ' ';
        cout << '\n';
        return;
    }
    for (auto &pair : mp) {
        if (pair.second!=0) {
            pair.second--;
            permutation[curr] = pair.first;
            genrate_unique_permutation(curr+1);
            pair.second++;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        mp[arr[i]]++;
        permutation[i]=-1;
        visited[i]=false;
    }
    
    sort(arr,arr+n);
    genrate_all_permutation(0);
    genrate_unique_permutation(0);

}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}