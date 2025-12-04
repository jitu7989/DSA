#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

class Solution {
public:
    bool validate(int start,int end, string s,bool can_have_decimal){
        int d = 0, di= INT32_MAX;

        for (int i = start; i < end; ++i) {
            if(s[i]=='.'){
                d++;di = i;
            }
        }
        if(d>1 || (d>0 && !can_have_decimal) ) return false;
        bool sign = false;
        int digit = 0;
        for (int i = start; i < min(di,end); ++i) {
            if(!isdigit(s[i])){
                if(i==start && (s[i]=='-' || s[i]=='+')){
                    if(sign) return false;
                    sign = true;
                }
                else return false;
            }
            else digit++;
        }
        int digit2 = 0;
        if(d){
            for (int i = di+1; i <end; ++i) {
                if(!isdigit(s[i])) return false;
                else digit2++;
            }
        }
        return digit || digit2;
    }
    bool isNumber(string s) {
        int es = 0,eIdx = -1, n=s.size();
        for (int i=0; i<n; i++){
            if(s[i]=='e' || s[i]=='E'){
                es++;
                eIdx = i;
            }
        }
        if(es>1) return false;
        if(es==1) return validate(0,eIdx,s,true) && validate(eIdx+1,n,s, false);
        return validate(0,n,s, true);
    }
};

int main(){
    Solution s;
//    s.isNumber(".0");
//    s.isNumber("0+1");
}