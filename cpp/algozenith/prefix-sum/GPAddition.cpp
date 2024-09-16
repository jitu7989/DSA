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

class ModUtil{
public:
    using ll = long long;
    ll mod = 1e9+7;
    ll mul(ll a, ll b){
        return do_mod((a%mod)*(b%mod));
    }
    ll add(ll a,ll b){
        return do_mod((a%mod)+(b%mod));
    }
    ll power(ll n,ll p){
        int ans = 1;
        while(p){
            if(p%2==0){
                n = mul(n,n);
                p/=2;
            }
            else{
                ans = mul(ans,n);
                --p;
            }
        }
        return ans;
    }

    ll divide(ll a,ll b){
        return mul(a, power(b,mod-2));
    }
    ll subtract(ll a,ll b){
        return do_mod(a-b);
    }
    ll do_mod(ll a){
        return ((a%mod)+mod)%mod;
    }
    ll inv(ll num,ll pow){
        return power(power(num,pow),mod-2);
    }
    ll inv(ll num){
        return power(num,mod-2);
    }
};

ModUtil mod_util;
void solve(){

    int n,q,k; cin >> n >> q >> k;
    vector<ll> A(n+2),B(n+2),K(n+2);

    fill(A.begin(),A.end(),0);
    fill(B.begin(),B.end(),0);
    fill(K.begin(),K.end(),1);
    for (int i = 1; i < n+1; ++i) {
        K[i] = mod_util.mul(K[i-1],k);
    }

    for (int i = 0; i < q; ++i) {
        int a,l,r; cin >> a >> l >> r;
        ll constant = mod_util.mul(a,mod_util.inv(k,l));
        A[l]   +=  constant;
        A[r+1] -=  constant;
    }

    for (int i = 1; i <= n; ++i) {
        A[i] = mod_util.add(A[i-1],A[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << mod_util.mul(A[i],K[i])<< ' ';
    }

}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}