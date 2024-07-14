#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


void solve(){
    int n,k,x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        cout << temp << " ";
        if(i==k){
            cout << x << " ";
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}