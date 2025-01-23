#include <bits/stdc++.h>;
using namespace std;




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;

    long long arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);
    for(int i=1; i<n; i++) arr[i] += arr[i-1];


    while(m--){
        int q;
        cin >> q;
        int ans = upper_bound(arr,arr+n,q)-arr;
        cout << ans << "\n";
    }
}