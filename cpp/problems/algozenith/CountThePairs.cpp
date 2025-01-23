#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;


void solve() {
    int n, x; cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; ++i)  cin >> arr[i];
    sort(arr, arr + n);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int el = x - arr[i];
        ll count = upper_bound(arr,arr+n,el)-arr;
        if(arr[i] <= x-arr[i])count--;
        ans += count;
    }
    cout << ans << "\n";

}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) solve();

    return 0;
}