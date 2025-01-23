#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int ans=0;
        long long freq[28];
        long long tempFreq[28];
        fill(freq, freq + 28, 0);

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            int idx = (c-'a')+1;
            freq[idx]++;
        }

        for (int i = 0; i < t; ++i) {
            fill(tempFreq, tempFreq + 28, 0);
            for (int i = 1; i <= 26; ++i) {
                int transformations = nums[i-1];
                int transformationsIdx = i;

                tempFreq[transformationsIdx+1] = (tempFreq[transformationsIdx+1]+freq[transformationsIdx])%mod;
                if( (transformationsIdx+transformations) > 26) {
                    tempFreq[0] = (tempFreq[0]+freq[transformationsIdx])%mod;
                    int ending = ((transformationsIdx+transformations)%26)+1;
                    tempFreq[ending] -= freq[transformationsIdx];
                }
                else {
                    int ending = transformationsIdx+transformations+1;
                    tempFreq[ending] = tempFreq[ending]%mod-freq[transformationsIdx]%mod;
                }

            }

            for (int i = 1; i <= 26 ; ++i) {
                tempFreq[i] = (tempFreq[i-1]%mod+tempFreq[i]%mod)%mod;
            }

            for (int i = 1; i <= 26; ++i) {
                freq[i] = tempFreq[i]%mod;
            }
        }

        for (int i = 1; i <= 26; ++i) {
            ans = (ans + ((int)freq[i])%mod)%mod;
        }

        return ans;
    }
};

int main() {

    string s = "abcyy";
    int t = 2;
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
    Solution solution;
    solution.lengthAfterTransformations(s, t,nums);

}