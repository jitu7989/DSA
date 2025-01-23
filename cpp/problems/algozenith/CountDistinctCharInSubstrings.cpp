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

    vector<queue<int>> posi(26);

    for(int i=0; i<n; i++){
        int aplhabet = str[i]-'a';
        posi[aplhabet].push(i);
    }
    ll score_of_unique_characters = 0;

    for (int i = 0; i < n; ++i) {
        int aplhabet = str[i]-'a';
        for (int j = 0; j < 26; ++j) {
            if (!posi[j].empty()) {
                int p = posi[j].front();
                score_of_unique_characters+=(n-p);
            };
        }
        posi[aplhabet].pop();
    }

    cout<< score_of_unique_characters <<"\n";

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