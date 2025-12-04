#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

vector<ii> get_factors(ll x) {
    vector<ii> ans;
    for (ll i = 2; i * i <= x; ++i) {
        if (!(x % i)) {
            int cnt = 0;
            while (!(x % i)) {
                cnt++;
                x /= i;
            }
            ans.push_back({i, cnt});
        }
    }

    return ans;
}


int main() {

}