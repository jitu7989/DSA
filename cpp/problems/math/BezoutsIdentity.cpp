#include <bits/stdc++.h>;
using namespace std;

int gcd(int a,int b){
    return !a ? b: gcd(b%a,a);
}
// A B C
// Ax + By = C
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    bool exist = c%gcd(a,b)==0;
    cout << (exist?"Yes":"No") << "\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}