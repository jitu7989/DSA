#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


void solve(){
    int n,m;
    string a,b;
    cin >> n >> m;
    cin >> a >> b;
    int mn = INT32_MAX;
    for (int i = 0; i <= n-m; ++i) {
        int cnt = 0;
        for (int j = 0,k=i; j < m; ++j,++k) {
            if(a[k]!=b[j]) cnt++;
        }
        mn = min(cnt,mn);
    }
    cout << mn << "\n";
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}