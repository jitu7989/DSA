// Given two arrays A of size N and B of size M and an integer K.
// Create a new array C of size N*M consisting of A[i]+B[j] for 1≤i≤N, 1≤j≤M.
// Find the Kth smallest element in the array C.

// Sample Input
// 1
// 3 3 6
// 1 2 3
// 4 5 6

#include <bits/stdc++.h>
using namespace std;
#define int long long;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int tc;
    cin >> tc;
    while(tc--) {
        int n,m,k;
        cin >> n >> m >> k;
        vector<ll> a(n), b(m);

        for (int i = 0; i < n; ++i)  {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i)  {
            cin >> b[i];
        }

        // Ensure n <= m
        if(n > m){
            swap(n,m);
            swap(a,b);
        }

        // Sort arrays
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        ll l = a[0] + b[0], h = a[n-1] + b[m-1];
        ll ans = l;

        while(l <= h) {
            ll mid = l + (h - l) / 2;
            int ne = 0;

            // Count how many sums are <= mid
            for (int i = 0; i < n; ++i) {
                ne += upper_bound(b.begin(), b.end(), mid - a[i]) - b.begin();
            }

            if(ne >= k) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}



