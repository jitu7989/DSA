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
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = (int)nums.size();
        vector<ll> diff(n);
        for (int i = 0; i < n; ++i)  diff[i] = nums[i]-target[i];
        ll operations = 0;
        bool posi = diff[0]>=0;
        int l=0;
        for (int i = 0; i < n; ++i) {
            if(posi && diff[i]<0) {
                posi= false;
                operations += get_ops(l,i-1,diff);
                l=i;
            }
            else if(!posi && diff[i]>=0){
                posi= true;
                operations += get_ops(l,i-1,diff);
                l=i;
            }
        }
        operations += get_ops(l,n-1,diff);
        return operations;
    }
    ll get_ops(int l, int r, vector<ll> &diff){
        ll ops = 0;
        ll prev = -1;
        for (int i = l; i <= r; ++i) {
            ll a = abs(diff[i]);
            if(prev==-1) ops += a;
            else if(prev<a) ops += a-prev;
            prev = a;
        }
        return ops;
    }

};



signed main(){

    Solution s;

    return 0;
}