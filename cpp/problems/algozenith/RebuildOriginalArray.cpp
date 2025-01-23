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

void solve(){

    multiset<ll> ans,prev,nums,tmp;
    ll n;
    cin >> n;
    for (ll i = 0; i < 1<<n; ++i) {
        ll temp; cin >> temp;
        nums.insert(temp);
    }
    nums.erase(nums.find(0));

    while(!nums.empty()){
        ll num = *nums.begin();

        for (const auto &item: prev){
            ll subsetSum = item+num;
            auto it = nums.find(subsetSum);
            if(it!=nums.end()) {
                tmp.insert(subsetSum);
                nums.erase(it);
            }
        }
        for (const auto &item: ans){
            ll subsetSum = item+num;
            auto it = nums.find(subsetSum);
            if(it!=nums.end()) nums.erase(it);
            tmp.insert(subsetSum);
        }
        for (const auto &item: tmp) prev.insert(item);
        ans.insert(num);
        nums.erase(nums.find(num));
    }

    for (const auto &item: ans) cout << item << " ";
    cout << "\n";
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tc;
    cin >> tc;
    while(tc--) solve();

    return 0;
}