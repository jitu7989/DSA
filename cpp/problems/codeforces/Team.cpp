#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;

    int temp = 0,x;
    int ans  = 0;
    while (n--) {
        x=0;
        for (int i=0;i<3;i++) {
            cin >> temp;
            x += temp;
        }
        if (x>=2) {
            ans++;
        }
    }
    cout << ans;

}
