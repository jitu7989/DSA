#include <bits/stdc++.h>;

using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

void solve() {

    int n;
    ll k;
    cin >> n >> k;
    ll arr[n];
    map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    priority_queue<ii> q;
    for (const auto &item: freq){
        q.emplace(item.second,item.first);
    }
    for (int i = 0; i < k; ++i) {
        auto &pair= q.top();
        ll el = pair.second;
        if(pair.first<=1) break;
        freq[el]--; q.pop();
        q.emplace(freq[el],el);
    }
    ll ans = (n * (n - 1)) / 2;
    for (const auto &item: freq){
        if(item.second>1) ans -= (item.second*(item.second-1))/2;
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