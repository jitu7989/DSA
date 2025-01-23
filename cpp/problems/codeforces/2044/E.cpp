#include <bits/stdc++.h>
using namespace std;
//
// 1 2 3
// 1 2 3 4 5 6
void solve() {

    long long n ,l1,r1,l2,r2; cin >> n >> l1 >> r1 >> l2 >> r2;

    long long ans;

    long long lowest_multiple_1 = l1/n;
    long long greatest_multiple_1 = r1/n;
    if(l1%n!=0) lowest_multiple_1++;

    for (int i = lowest_multiple_1; i <= greatest_multiple_1; ++i) {
        
    }

    long long lowest_multiple_2 = l2/n;
    long long greatest_multiple_2 = r2/n;

    if(l1%n==0) lowest_multiple_1--;
    if(l2%n==0) lowest_multiple_2--;

    cout << (greatest_multiple_1-lowest_multiple_1)*(greatest_multiple_2-lowest_multiple_2) << '\n';


}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) solve();

    return 0;
}
