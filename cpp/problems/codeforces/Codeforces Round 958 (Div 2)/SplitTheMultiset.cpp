#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;


void solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    --k;
    while (n > 1) {
        n -= k;
        ans++;
    }
    cout << ans << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) solve();
}