#include <bits/stdc++.h>
using namespace std;

using ll  = long long;



class Solution {
public:
    ll ONE  = 1LL;
    ll get_number_of_ones(ll mid)  {

        ll score = 0;
        for (int i = 0; i <= 60; i++) {
            ll total = (ONE<<(i+ONE));
            ll total_ones_in_periodicity = (ONE<<i);
            ll left = (total_ones_in_periodicity)*(mid/total);
            ll remaining = max(((mid%total)+ONE)-total_ones_in_periodicity,0LL);
            score += (left+remaining);
        }
        return score;
    };

    ll find_the_number(int k) {
        ll low = 0, high = 1e15;
        ll ans = 0;

        while (low<=high) {
            ll mid = low+((high-low)/2L);
            if (get_number_of_ones(mid)<k) {
                ans = mid;
                low = mid+ONE;
            }
            else {
                high = mid-ONE;
            }
        }
        return ans;
    }

    ll kthPosition(ll num, ll k){

        for(int i=0; i<60; i++){
            if( num&(1LL<<i) ){
                k--;
            }
            if(k==0) return i;
        }
        return 0;
    }
    ll find_number_of_bits_till_now(ll x){

        ll x = 0;


    }

    ll findTheKthBit(int k) {

        ll last_number = find_the_number(k);
        ll find_no_of_ones = get_number_of_ones(last_number-1);
        ll kth_idx_in_num = kthPosition(last_number,k-find_no_of_ones);
        ll number_of_bits = find_number_of_bits_till_now(k-1);
        ll kthBit = number_of_bits+kth_idx_in_num+1;
        return kthBit;
    }
};
// 01 2 3  4  5  6  7   8   9  10  11  12  13  14  15   16
// 0101110011010111110001100101011101001110110111111100001
//


int main(){

}