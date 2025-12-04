#include <bits/stdc++.h>
using namespace std;


void solve() {

    long long n; cin >> n;
    vector<long long> arr(n);
    set<long long> ss,snapshot;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ss.insert(arr[i]);

    }
    snapshot = ss;
    int idx = 0;
    int base_freq = 1;
    int elements = 0;

    vector<int> freq(n+1,0);

    while (idx<n) {
        if (elements==ss.size()) {
            elements = 0;
            base_freq++;
            snapshot = ss;
        }

        if (freq[arr[idx]]<base_freq) {
            freq[arr[idx]]++;
            elements++;
            snapshot.erase(arr[idx]);
            cout << arr[idx] <<" ";
        }
        else {
            int x = *snapshot.begin();
            snapshot.erase(snapshot.begin());
            elements++;
            freq[x]++;
            cout << x <<" ";
        }
        idx++;
    }
    cout << '\n';

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
