#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<ll,ll>;
using vii = vector<ii>;
using vi  = vector<int>;
typedef set<int> si;
typedef map<string, int> msi;

void solve(){
    int n; cin>>n;

    string str; cin >> str;

    vector<vector<int>> posi(26,vector<int>(0));

    for(int i=0; i<n; i++){
        int aplhabet = str[i]-'a';
        posi[aplhabet].push_back(i);
    }
    // a b b b a c d e a
    // 0 1 2 3 4 5 6 7 8
    ll ans = 0;
    for (int i = 0; i < 26; ++i) {
        int len = posi[i].size();
        for (int j = 0; j < len; ++j) {


            int mid=posi[i][j],left,right;
            if (j>0)  left = posi[i][j-1];
            else left = -1;
            if (j == len-1) right = n;
            else right = posi[i][j+1];

            left = mid - left;
            right = right-mid;

            ans += (left*right);
        }
    }
    cout<<ans<<"\n";

}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();

    return 0;
}