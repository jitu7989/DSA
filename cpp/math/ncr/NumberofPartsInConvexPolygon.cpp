#include <bits/stdc++.h>;

using namespace std;
using ll = long long;


class ModUtil {
public:
    using ll = long long;
    ll MOD = 1e9 + 7;

    ll mul(ll a, ll b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    ll add(ll a, ll b) {
        return ((a % MOD) + (b % MOD)) % MOD;
    }

    ll power(ll n, ll p) {
        int ans = 1;
        while (p) {
            if (p % 2 == 0) {
                n = mul(n, n);
                p /= 2;
            } else {
                ans = mul(ans, n);
                --p;
            }
        }
        return ans;
    }

    ll divide(ll a, ll b) {
        return mul(a, power(b, MOD - 2));
    }

    ll subtract(ll a, ll b) {
        return (a - b + MOD) % MOD;
    }

    ll mod(ll a) {
        return a % MOD;
    }
};

ModUtil modUtil;


void solve() {
    ll n;
    cin >> n;
    ll ans = 1;
    ll temp = modUtil.divide(modUtil.mod(modUtil.mul(n,(n-1))),2);
    for (int i = 0; i <= 3; ++i)
        ans = modUtil.mul(ans, n - i);
    ans = modUtil.divide(ans, 24);
    ans = modUtil.add(ans,temp);
    ans = modUtil.add(ans,1);
    ans = modUtil.subtract(ans, n);
    cout << modUtil.mod(ans) << "\n";
}


int main() {
    int a = 2147483646;
    int b = 2147483645;

    int res1 = (a % 11 * b % 11) % 11;
    int res2 = (a * b) % 11;
    int res3 = (a * 1LL * b) % 11;
    int res4 = (a * b * 1LL) % 11;

    cout << res1 << " " << res2 << " " << res3 << " " << res4;

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    int tc;
//    cin >> tc;
//    while (tc--) solve();
}