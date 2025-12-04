#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

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

int comp_first(ii a,ii b){
    if(a.first<b.first) return -1;
    return a.first>b.first;
}

ll search_k_val(int n,vector<ii> &pairs,ll k){

    int l = 1, h = n;

    ll ans = pairs[n].first;
    while(l<=h){
        int mid = l+((h-l)/2);

        if(k<=pairs[mid].second){
            ans = pairs[mid].first;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(ans==LONG_LONG_MAX) return -1;
    return ans;
}
void solve(){

    int n,m,q; cin >> n >> m >> q;
    vector<ll> arr(n+2),freq(n+2);
    fill(arr.begin(),arr.end(),0);

    for (int i = 1; i <= n; ++i)  cin >> arr[i];
    for (int i = 0; i < m; ++i) {
        int l,r;cin >> l >> r;
        freq[l] += 1;
        freq[r+1] -= 1;
    }
    for (int i = 1; i <= n; ++i) {
        freq[i] += freq[i-1];
    }
    vector<ii> pairs(n+2);
    pairs[0].first=LONG_LONG_MIN;
    pairs[0].second=0;

    pairs[n+1].first=LONG_LONG_MAX;
    pairs[n+1].second=LONG_LONG_MAX;

    for (int i = 1; i <= n; ++i) {
        pairs[i].first  = arr[i];
        pairs[i].second = freq[i];
    }
    sort(pairs.begin(),pairs.end());

    for (int i = 1; i <= n; ++i) {
        pairs[i].second += pairs[i-1].second;
    }


    for (int i = 0; i < q; ++i) {
        ll k; cin >> k;
        cout << search_k_val(n+1,pairs,k) << ' ';
    }
    cout << '\n';

}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();

    return 0;
}