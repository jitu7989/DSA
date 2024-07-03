#include <bits/stdc++.h>;
using namespace std;
using ll = long long;


void solve(){
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 0; i <= n; ++i) arr[i] = 0;
    for (int i = 0; i < n; ++i)  {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    ll ans = INT32_MAX;
    for (int i = 1; i <= n ; ++i) {
        ans = min((n-(ll)arr[i])*i,ans);
    }

    cout << ans << "\n";

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}