#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e5*2+10;
ll fact[MAX];

class ModUtil{
public:
    using ll = long long;
    ll mod = 1e9+7;
    ll mul(ll a, ll b){
        return ((a%mod)*(b%mod))%mod;
    }
    ll add(ll a,ll b){
        return ((a%mod)+(b%mod))%mod;
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
        return (a%mod-b%mod+mod)%mod;
    }
    ll do_mod(ll a){
        return a%mod;
    }
};
ModUtil modUtil;

void solve(){
    ll n,m;
    cin >> n >> m;
    ll ans = fact[n+m];
    ans = modUtil.divide(ans,fact[n]);
    ans = modUtil.divide(ans,fact[m]);
    cout << ans << "\n";
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0]=1;
    for (ll i = 1; i < MAX; ++i) {
        fact[i] = modUtil.mul(i,fact[i-1]);
    }

    ll tc;
    cin >> tc;
    while(tc--) solve();
}