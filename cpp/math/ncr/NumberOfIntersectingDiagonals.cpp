#include <bits/stdc++.h>;
using namespace std;
using ll = long long;

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
        return (a-b+mod)%mod;
    }
    ll do_mod(ll a){
        return a%mod;
    }
};
ModUtil modUtil;

void solve(){
    ll n;cin >>n;
    if(n<=3){
        cout << 0 << "\n";
        return;
    }


    ll ans = 1;
    for (int i = 0; i <= 3; ++i) {
        ans = modUtil.mul(ans,n-i);
    }
    cout << modUtil.divide(ans,24) << "\n";

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}