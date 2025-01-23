#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}sdf
ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

string cdo = "![CDATA[";
string cdc = "]]>";


class Solution {
public:

    int findCDataEnd(int i, string &s){
        int j = i,p=0;
        while(j<s.length() && p<cdo.length() && s[j]==cdo[p]) {j++;p++;}
        if(p!=cdo.length()) return -1;
        i=j;
        p=0;
        while(i<s.length() && p<cdo.length()){
            if(s[i]==']'){
                j=i,p=0;
                while(j<s.length() && p<cdo.length() && s[j]==cdc[p]) {j++;p++;}
                if(p==cdc.length()) return j;
            }
            i++;
        }
        return -1;
    }
    pair<string,int> getTagName(int i, string &s){
        int j = i;
        string ans;
        while(j<s.length() && s[j]!='>'){
            if( !(s[j]>='A' && s[j]<='Z') ) return {"",-1};
            ans+=s[j++];
        }
        if(s[j]=='>') j++;
        if(ans.length()<=9) return {ans,j};
        return {"",-1};
    }
    bool isValid(string s) {
        int i = 0,n = s.size();
        stack<string> stk;
        int count = 0;
        while(i<n){
            if(s[i]=='<'){
                i++;
                if(i<s.length() && s[i]=='!'){
                    int j = findCDataEnd(i,s);
                    if(j==-1 || stk.empty()) return 0;
                    i = j;
                }
                else if(i<s.length() && s[i]=='/'){
                    i++;
                    pair<string,int> tag_name = getTagName(i,s);
                    if(tag_name.first=="") return 0;
                    if(!stk.empty() && stk.top()==tag_name.first) stk.pop();
                    else return false;
                    i = tag_name.second;
                }
                else if(i<s.length()){
                    pair<string,int> tag_name = getTagName(i,s);
                    if(tag_name.first=="") return 0;
                    if(stk.empty()) count++;
                    stk.push(tag_name.first);
                    i = tag_name.second;
                }
                else return 0;
            }
            else {
                if(stk.empty())return 0;
                i++;
            }
        }
        return stk.empty() && count==1;
    }
};

int main(){
    Solution s;
    cout << s.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>");
}