/*
 * Description
 * You have given a grid of N x M.
 * You are initially at position A(0, 0) and you want to reach B(N, M). From the given cell (i, j), we are allowed to move to cells (i + 1, j) and (i, j + 1) only.
 * Find the number of different ways to reach B from A?
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e5*2+10;
ll fact[MAX];

class ModUtil{
public:
    using ll = long long;
    ll MOD = 1e9 + 7;
    ll mul(ll a, ll b){
        return ((a % MOD) * (b % MOD)) % MOD;
    }
    ll add(ll a,ll b){
        return ((a % MOD) + (b % MOD)) % MOD;
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
        return mul(a, power(b, MOD - 2));
    }
    ll subtract(ll a,ll b){
        return (a % MOD - b % MOD + MOD) % MOD;
    }
    ll do_mod(ll a){
        return a % MOD;
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