#include <bits/stdc++.h>;


using namespace std;
using ll = long long;



void solve(){
    ll n,k;
    cin >> n >> k;
    ll a[k];

    for (ll i = 0; i < k; ++i) {
        cin >> a[i];
    }

    ll mx = 0;

    for (ll i = 0; i < k; ++i) {
        if(a[i]>a[mx]){
            mx = i;
        }
    }

    long long count = 0;
    for (ll i = 0; i < k; ++i) {
        if(i!=mx){
            if(a[i]==1){
                count++;
            }
            else{
                count+=(2*a[i])-1;
            }
        }
    }
    cout << count << "\n";

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tc;
    cin >> tc;
    while(tc--) solve();
}