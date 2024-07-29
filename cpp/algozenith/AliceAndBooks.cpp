#include <bits/stdc++.h>;
using namespace std;
using ll = long long;

void solve(){
    int n;cin >> n;
    ll q,max = 1;
    multiset<ll> st;
    for (int i = 1; i <= n; ++i) {
        cin >> q;
        if(q>max) st.insert(q);
        while(!st.empty() && max>=*st.begin()) st.erase(*st.begin());
        if(st.size()>max) max++;
        cout << max << " ";
    }
    cout <<  "\n";
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}