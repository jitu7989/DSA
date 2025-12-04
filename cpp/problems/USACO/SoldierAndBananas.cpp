#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,n,w; cin >> k >> n >> w;
    int ans = (((w*(w+1))/2)*k)-n;
    if (ans<0) ans = 0;
    cout << ans;
}
