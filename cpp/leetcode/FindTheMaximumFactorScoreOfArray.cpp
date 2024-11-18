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

    long long gcd(long long a,long long b){
        return !a ? b: gcd(b%a,a);
    }
    long long lcm(long long a,long long b){
        return (a*b)/gcd(a,b);
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int toRemove = -1;
        while(toRemove < n) {
            bool first = true;

            long long finalLCM = 0;
            long long finalGCD = 0;

            for (int i = 0; i < n; ++i) {
                if(i == toRemove) {
                    continue;
                }
                if(first) {
                    first = false;
                    finalGCD = nums[i];
                    finalLCM = nums[i];
                }
                else {
                    finalGCD = gcd(nums[i], finalGCD);
                    finalLCM = lcm(nums[i], finalLCM);
                }
            }
            toRemove++;
            ans = max(ans,finalGCD*finalLCM);
        }
        return ans;
    }
};


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution s;

    vector<int> nums1 = {2,4,8,16};
    s.maxScore(nums1);

    return 0;
}