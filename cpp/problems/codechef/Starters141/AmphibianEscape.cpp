
// TODO:
#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


void solve(){
    ll n,k,h;
    cin >> n >> k >> h;

    int every_sec_to_jump = ceil(h/k);
    if(n>h){
        ll s = n-every_sec_to_jump;
        ll sumOfNums = h-(every_sec_to_jump+1);
        ll square = (n-(h-1))*n;
        ll sum = (sumOfNums*(sumOfNums+1))/2;
        cout << square+sum;
    }
    else{
        ll s = n-every_sec_to_jump;
        if(s<=0){
            cout << "0";
        }
        else{
            cout << s*(s+1)/2;
        }
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