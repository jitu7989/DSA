#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
#define F first;
#define SC second;


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


struct RageMantainance{

    set<ii> ranges;
    void fill_ranges(ll l, ll r){
        auto it  = ranges.upper_bound({l,1e9});
        if(it!=ranges.begin()){
            it--;
            if(it->second>=l){
                l = min(l,it->first);
                r = max(r,it->second);
                ranges.erase(it);
            }
        }

        it = ranges.upper_bound({r,1e9});
        if(it!=ranges.begin()){
            it--;
            if(it->second>=r){
                l = min(l,it->first);
                r = it->second;
                ranges.erase(it);
            }
        }

        while(1){
            it = ranges.lower_bound({l,0});
            if(it==ranges.end() || it->first>r)break;
            else ranges.erase(it);
        }
        ranges.insert({l,r});
    }

    void clear_ranges(ll l, ll r){

    }

//    Finds Weather the point exists in a range
    bool check_point(ll x){
        auto it = ranges.upper_bound({x,1e9});
        if(it==ranges.begin()) return 0;
        it--;
        return it->second>=x;
    }
//    Finds weather the range intersect any range
    bool check_range_any(ll x,ll y){
        return check_point(x) || check_point(y);
    }

//    Find weather the range cover whole range
//
// Given Range  ______________________________
// Existing Ranges     ____________
    bool check_range_all(ll x,ll y){
        auto it = ranges.upper_bound({x,1e9});
        if(it==ranges.begin()) return 0;
        it--;
        return it->second<=y;
    }
};

void solve(){
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();

    return 0;
}