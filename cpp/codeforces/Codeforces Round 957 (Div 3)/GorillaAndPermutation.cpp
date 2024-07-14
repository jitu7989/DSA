#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


void solve(){

    int n,m,k;

    cin >> n >> m >> k;

    for (int i = n; i >= k ; i--) {
        cout << i << " ";
    }
    for (int i = m+1; i < k ; i++) {
        cout << i << " ";
    }
    for (int i = 1; i <= m; i++) {
        cout << i << " ";
    }
    cout << "\n";
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}