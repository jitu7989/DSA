#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

// O( log(min(a,b) )
int gcd(int a,int b){
    return !a ? b: gcd(b%a,a);
}


int main() {

}