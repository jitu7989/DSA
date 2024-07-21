#include <bits/stdc++.h>;

using namespace std;


void solve() {

    int n, m;
    cin >> n >> m;
    vector<int> arr;
    arr.resize(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(),arr.end());
    for (int i = 0; i < m; ++i) {
        int q,num;
        cin >> q >> num;
//        2 3 5 3
//        3 0
//1 x - Find the smallest Element ≥ x
//2 x - Find the smallest Element > x
//3 x - Find the number of elements ≤ x
//4 x - Find the number of elements < x
// lower_bound = the first index i where arr[i] >= M
        int ans;
        if(q==1){
            auto temp = lower_bound(arr.begin(),arr.end(),num);
            if(temp==arr.end()) cout << -1    << " ";
            else                cout << *temp << " ";
        }
        else if(q==2){
            auto temp = lower_bound(arr.begin(),arr.end(),num+1);
            if(temp==arr.end()) cout << -1    << " ";
            else                cout << *temp << " ";

        }
        else if(q==3){
            ans = upper_bound(arr.begin(),arr.end(),num)-arr.begin();
            cout << ans << " ";
        }
        else{
            ans = upper_bound(arr.begin(),arr.end(),num-1)-arr.begin();
            cout << ans << " ";
        }

    }
    cout << "\n";
}


int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) solve();
}