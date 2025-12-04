#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
vector<int> a,s;

void solve(){
    int n,x;
    cin >> n >> x;
    if(n>a.size()) {
        a.resize(n);
        s.resize(n);
    }
    
    for (int i = 0; i < n; ++i)  cin >> a[i];
    if(n>=2*n) {
        cout << "YES" << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) s[i] = a[i];
    sort(s.begin(),s.end());
    bool f = true;
    for (int i=n-x; i<x && f; ++i) f = a[i]==s[i];
    cout << (f?"YES":"NO") << '\n';
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();

    return 0;
}
