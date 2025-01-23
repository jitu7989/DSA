#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<ll> get_divisors(ll x) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= x; ++i) {
        if (!(x % i)) {
            divisors.push_back(i);
            if (i * i != x) divisors.push_back(x / i);
        }
    }
}

int main() {

}