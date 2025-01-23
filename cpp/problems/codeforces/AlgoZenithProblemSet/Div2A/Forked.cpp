#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

//---- Debugger ---- //
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

int count(ll tx,ll ty, ll xk,ll yk,ll xq,ll yq){
    return (abs(xk-xq)==tx && abs(yk-yq)==ty) || abs(xk-xq)==ty && abs(yk-yq)==tx;
}
void solve(){
    ll tx,ty, xk,yk,xq,yq;
    cin >> tx >> ty >>  xk >> yk >> xq >> yq;

    int ans = 0;

    ans += count(tx,ty, xk+ty, yk+tx, xq,yq);
    ans += count(tx,ty, xk+ty, yk-tx, xq,yq);
    ans += count(tx,ty, xk-ty, yk-tx, xq,yq);
    ans += count(tx,ty, xk-ty, yk+tx, xq,yq);

    if(tx!=ty){
        ans += count(tx,ty, xk+tx, yk+ty, xq,yq);
        ans += count(tx,ty, xk+tx, yk-ty, xq,yq);
        ans += count(tx,ty, xk-tx, yk+ty, xq,yq);
        ans += count(tx,ty, xk-tx, yk-ty, xq,yq);
    }

    cout << ans << "\n";
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