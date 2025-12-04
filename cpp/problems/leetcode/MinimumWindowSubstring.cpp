#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;



class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size(),m=t.size();
        unordered_map<int,int> freqMap;
        unordered_map<int,int> map;
        for (auto item: t) freqMap[item-'A']++;

        int min = INT32_MAX;
        int l=0,r=0;

        int i=0,j=0;
        while(j<n){

            int curr = s[j]-'A';
            map[curr]++;
//            if(i!=j && map[curr]>freqMap[curr] && (s[i]-'A')==curr) i++;
            while(i<=j && (!freqMap[s[i]-'A'] || freqMap[s[i]-'A']<map[s[i]-'A'])) {
                map[s[i]-'A']--;
                if(!map[s[i]-'A']) map.erase(s[i]-'A');
                i++;
            }

            bool flag=true;
            for (const auto &item: freqMap){
                if(item.second>map[item.first]){
                    flag = false;break;
                }
            }
            if(flag && min>(j-i+1)){
                l=i;
                r=j;
                min=r-l+1;
            }

            j++;
        }
        j--;
        bool flag=true;
        for (const auto &item: freqMap){
            if(item.second>map[item.first]){
                flag = false;break;
            }
        }
        if(j>=i && flag && min>(j-i+1)){
            l=i;
            r=j;
            min=r-l+1;
        }

        if(min==INT32_MAX) return "";
        else {
            string ans;
            for (int k = l; k <=r; ++k) {
                ans+=s[k];
            }
            return ans;
        }
    }
};

int main(){
    Solution s;
    cout << s.minWindow("a","a");
}