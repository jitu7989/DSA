//
// Created by jitendra on 12/22/24.
//
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;

void solve() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> question_set(m),known_questions(k);

    for (int i = 0; i < m; ++i) cin >> question_set[i];
    for (int i = 0; i < k; ++i) cin >> known_questions[i];

    if (n==k) {
        cout << string(m,'1') << '\n';
        return;
    }
    if ((n-1)!=k) {
        cout << string(m,'0') << '\n';
        return;
    }
    ll sum_till_n = (n*(n+1))/2LL;
    ll sum_of_know_question = accumulate(known_questions.begin(), known_questions.end(),0LL);
    string result(m, '0');
    for (int i = 0; i < m; ++i) {
        if(sum_till_n-question_set[i]==sum_of_know_question) result[i]='1';
    }
    cout << result << '\n';
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