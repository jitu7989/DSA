#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    long long a,b,x,y; cin >> a >> b >> x >> y;
    if(x>y) swap(x,y);
    if(a>b) swap(a,b);

    long long ans = b-a;
    ans =  min(ans,abs(a-x)+abs(b-y));

    cout << ans;




}
