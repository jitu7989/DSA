#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<ll,ll>;
using vii = vector<ii>;
using vi  = vector<int>;
typedef set<int> si;
typedef map<string, int> msi;

#define INF 1000000000;

//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr);
// to clear array of integers


//---- Debugger ---- //
int add_debugger = 0;
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
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}


class Solution {
public:
    int minimumScore(string s, string t) {
        vector<int> pre(s.length(), -1),suf(s.length(), t.length());
        int a = -1,b = t.length();
        for (int i = 0; i < s.length(); ++i) {
            if ((a+1)<t.length() && s[i]==t[a+1]) a++;
            pre[i] = a;

            if ( (b-1)>=0 && s[(s.length()-1)-i]==t[b-1]) b--;
            suf[(s.length()-1)-i] = b;
        }
        int mn = t.length();
        for (int i = 0; i < s.length(); ++i) {
            // cout << "i: " << i << ' ' << pre[i]+1 << ' ' << suf[i] << ' '  << min(mn,max(suf[i]-(pre[i]+1),0)) << endl;
            int lp = i==0?-1:pre[i-1];
            int rp = i==s.length()-1?s.length():suf[i+1];
            if (lp!=pre[i] && rp!=suf[i]) mn = min(mn,max(suf[i]-(pre[i]),0));
            else mn = min(mn,max(suf[i]-(pre[i]+1),0));
        }
        // pr(pre);
        // pr(suf);
        cout << mn << endl;
        // cout << "=======================================" << '\n' << endl;
        return mn;
    }
};


// a  c  d  e  d  c  d  b  a  b  e  c  d  b  e  b  d  a
// b  b  e  c  d  d  b
// 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
// -1 -1 -1 -1 -1 -1 -1 0  0  1  2  3  4  4  4  4  5  5
//                                     5  6  6  6  7  7

 signed main(){
    Solution s;
    s.minimumScore("acdedcdbabecdbebda","bbecddb");
    s.minimumScore("abacaba","bzaa");
    s.minimumScore("dcadebdecbeaedd","dcdadeb");
    return 0;
}