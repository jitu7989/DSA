#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n; cin >> n;
  ll sum = 0;
  ll x; 
  for(ll i; i<n-1; i++){
    cin >> x;
    sum += x;
  }
  cout << ((n*(n+1))/2)-sum << " ";
  return 0;
}
