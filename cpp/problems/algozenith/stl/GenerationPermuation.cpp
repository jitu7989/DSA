#include <bits/stdc++.h>;

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;


void solve() {
    int n, m;
    cin >> n;
    set<int> q;
    while (n--) {

        string s;
        cin >> s;
        if (s == "add") {
            int temp;
            cin >> temp;
            q.push_back(temp);
        } else if (s == "remove") {
            if(!q.empty()) q.pop_back();
        } else if (s == "find") {
            int temp;
            cin >> temp;
            q.push_front(temp);
        } else if (s == "findpos") {
            if(!q.empty()) q.pop_front();
        }
    }

}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) solve();
}