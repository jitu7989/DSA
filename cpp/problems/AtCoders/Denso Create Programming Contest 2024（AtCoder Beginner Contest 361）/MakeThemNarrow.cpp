#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if(n-k==1){
        cout << 0;
        return;
    }
    sort(arr.begin(),arr.end());
    int mn = INT32_MAX;
    for (int i = 0,j=n-1-k; i <= k; i++,j++) {
        mn = min(arr[j]-arr[i],mn);
    }
    cout << mn;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}