#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

bool comp(ii p1, ii p2){
    return p1.first+p1.second > p2.first+p2.second;
}
void solve(){

    int n; cin >> n;
    vector<ii> arr(n,{0,0});
    for (int i = 0; i < n; ++i)  cin >> arr[i].first;
    for (int i = 0; i < n; ++i)  cin >> arr[i].second;
    sort(arr.begin(),arr.end(),comp);

    ll a=0,b=0;
    for (int i = 0; i < n; ++i) {
        if(i&1) b+=arr[i].second;
        else    a+=arr[i].first;
    }
    if(a==b)     cout << "Tie\n";
    else if(a<b) cout << "Bob\n";
    else         cout << "Alice\n";
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