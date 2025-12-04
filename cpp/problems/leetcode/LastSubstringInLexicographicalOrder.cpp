#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

//---- Debugger ---- //
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
    string lastSubstring(string s) {
        int n = s.length();
        int j = n;
        ll looped = 0;
        for (int i = n-1; i >= 0 ; i--) {
            int a=i,b=j;
            while (b<n && a<j && s[a]==s[b] )  {
                looped++;
                a++;
                b++;
            }
            looped++;
            if (b==n || a==j || s[a]>s[b] ) j=i;
        }
        cout << looped << endl;
        return s.substr(j);
    }
};


class Solution2 {
public:

//  aaaaaaaaaaaaaaab

    string lastSubstring(string s) {
        int n = s.length(),i=0, j=1, k=0;
        while (j+k<n) {
            if (s[i+k]==s[j+k]) k++;
            else if (s[i+k]<s[j+k]) i=max(i+k+1,j),j=i+1,k=0;
            else j+=k+1,k=0;
        }
        return s.substr(i);
    }
};

signed main(){


    string str = "asglhasklhgeosdngs";
    Solution s;
    Solution2 s2;

    s.lastSubstring(str);
    s2.lastSubstring(str);

    return 0;
}