#include <bits/stdc++.h>;
using namespace std;

long long bin_pow(long long x, long long p, long long prime){
    long long ans = 1;
    while(p){
        if(p&1){
            ans = (ans*x)%prime;
            p--;
        }
        else{
            x = (x*x)%prime;
            p /= 2;
        }
    }
    return ans;
}


void solve(){
    long long  a,b,c,d;
    cin >> a >> b >> c >> d;

    long long x = bin_pow(a,bin_pow(b,c,d),d);

    cout << (x+d)%d << "\n";

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}