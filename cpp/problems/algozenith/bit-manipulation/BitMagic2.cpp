#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<ll,ll>;
using vii = vector<ii>;
using vi  = vector<int>;
typedef set<int> si;
typedef map<string, int> msi;
ll pow2_n(ll x) {
    if (x <= 1)return 2;
    return (1LL << (64 - __builtin_clzll(x - 1))); // 2^(64 - leading zeroes in bits).
}
signed main() {



    ll q,n;
    cin >> q;

    ll one=1;
    ll zero=0;
    while (q--) {
        cin >> n;
        ll one = 1LL;
        ll l=-1,r=-1;

        for(ll i=63; i>=0; i--)  {
          ll power = (one<<i);
          ll x = (n&power)?one:zero;
          cout << x;
          if(x) {
              if (l==-1LL) l=i;
             r=i;
          }
        }
        cout << "\n";

        ll is_two_power = ((n&(n-1LL))==zero);

        cout << l << '\n';
        cout << r << '\n';
        cout << is_two_power << '\n';
        if (l==-1LL) {
            cout << l << '\n';
        }
        else if (is_two_power) {
            cout << l << '\n';
        }
        else {
            cout << l+1 << '\n';
        }
        cout << pow2_n(n);


    }

    return 0;
}
