#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
ll mod = 1e9+7;

class Solution {
public:

    ll gcd(ll a,ll b){
        return !a ? b: gcd(b%a,a);
    }
    ll lcm(ll a,ll b){
        return (a*b)/gcd(a,b);
    }

    ll get_nums(ll a, ll b, ll mid) {
        if(a==b) return mid/a;
        ll mn = min(a,b);
        ll mx = max(a,b);

        ll lm = lcm(mn,mx);
        ll overlap= lm/mn;

        ll x = mid/mn;
        ll y = mid/mx;

        x -= (x/overlap);
        return x+y;
    }

    int nthMagicalNumber(int n, int a, int b) {

        ll l = (ll)min(a,b), h = (ll)max(a,b)*n;
        ll i=(ll)n;
        int ans = -1;
        while(l<=h){
            ll mid = l+(h-l)/2;
            ll nums = get_nums(a,b,mid);
            if(nums<i){
                l = mid+1;
            }
            else{
                ans = (int)(mid%mod);
                h = mid-1;
            }
        }
        return ans;
    }
};
