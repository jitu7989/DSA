#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

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

    int longestSubarray_brute_force(int n, vector<int> &arr) {
        // code here
        int ans=-1;

        ll p[n+1];
        p[0] = 0;
        for (int i = 1; i <=n; ++i) {
            p[i] = arr[i]+p[i-1];
        }

        for(int i=0;i<n;i++){
            int count=0;
            int sum=0;
            for(int j=i;j<n;j++) {
                count++;
                sum += arr[j];
                if(count == sum){
                    cout << i << " "<< j <<" " << count <<  "\n";
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }

    int longestSubarray(int n, vector<int> &arr) {

        map<ll,int> mp;
        mp[0] = -1;
        ll sum = 0;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            sum+=(arr[i]-1);
            auto it = mp.find(sum);
            if(it!=mp.end()) ans = max(ans,i-mp[sum]);
            else mp[sum]=i;
        }
        return ans;
    }
};
int main(){
    Solution solutio;
    int n;cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    solutio.longestSubarray(n,v);
}

