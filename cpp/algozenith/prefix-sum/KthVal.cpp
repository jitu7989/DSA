#include <bits/stdc++.h>;
using namespace std;


void solve(){
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> a(n+1);
    vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int l,r;
        cin >> l >> r;
        p[l]++;
        if( (r+1) <= n ){
            p[r+1]--;
        }
    }

    for (int i = 1; i <= n; ++i) {
        p[i] += p[i-1];
        a[i] += p[i];
    }
    sort(a.begin(),a.end());

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}