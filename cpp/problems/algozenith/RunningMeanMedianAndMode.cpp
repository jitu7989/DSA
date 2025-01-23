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
class ModUtil{
public:
    using ll = long long;
    ll mod = 1e9+7;
    ll mul(ll a, ll b){
        return ((a%mod)*(b%mod))%mod;
    }
    ll add(ll a,ll b){
        return ((a%mod)+(b%mod))%mod;
    }
    ll power(ll n,ll p){
        int ans = 1;
        while(p){
            if(p%2==0){
                n = mul(n,n);
                p/=2;
            }
            else{
                ans = mul(ans,n);
                --p;
            }
        }
        return ans;
    }

    ll divide(ll a,ll b){
        return mul(a, power(b,mod-2));
    }
    ll subtract(ll a,ll b){
        return (a-b+mod)%mod;
    }
    ll do_mod(ll a){
        return a%mod;
    }
};



struct Mean{
    ModUtil mod;
    ll sum=0,cnt=0;
    void insert(ll x){
        sum = mod.add(sum,x);
        cnt = mod.add(cnt,1);
    };
    void remove(ll x){
        sum = mod.subtract(sum,x);
        cnt = mod.subtract(cnt,1);
    };
    ll getMean(){
        if(cnt==0) return -1;
        return mod.divide(sum,cnt);
    }
};

struct Median{
    ModUtil mod;
    multiset<ll> smaller_partition;
    multiset<ll> larger_partition;

    void insert(ll x){
        if(smaller_partition.empty()) {
            smaller_partition.insert(x);
            return;
        }
        if(x<=*smaller_partition.rbegin()) smaller_partition.insert(x);
        else larger_partition.insert(x);
        rebalance();
    }

    void remove(ll x){
        auto it  = smaller_partition.find(x);
        if(it!=smaller_partition.end()) smaller_partition.erase(it);
        else larger_partition.erase(larger_partition.find(x));
        rebalance();
    }

    void rebalance(){
        while(!larger_partition.empty() && smaller_partition.size()<larger_partition.size()){
            ll it = *larger_partition.begin();
            smaller_partition.insert(it);
            larger_partition.erase(larger_partition.find(it));
        }
        while(!smaller_partition.empty() && (int) (smaller_partition.size()-larger_partition.size())>1 ){
            ll it = *smaller_partition.rbegin();
            larger_partition.insert(it);
            smaller_partition.erase(smaller_partition.find(it));
        }
    }

    ll get_median(){
        if(smaller_partition.empty()) return -1;
        ll x = *smaller_partition.rbegin();
        if( (smaller_partition.size()+larger_partition.size())&1 ) return x;
        ll y = *larger_partition.begin();
        return mod.divide(mod.add(x,y),2);
    }
};

struct Mode{

    unordered_map<ll,ll> freqMap;
    map<ll,set<ll>> inverseFreqMap;

    void insert(ll x){
        if(freqMap.find(x)==freqMap.end()){
            freqMap[x]++;
            inverseFreqMap[1].insert(x);
        }
        else{
            remove_inverse_freq(x,freqMap[x]);
            freqMap[x]++;
            inverseFreqMap[freqMap[x]].insert(x);
        }
    }
    void remove(ll x){
        remove_inverse_freq(x,freqMap[x]);
        freqMap[x]--;
        if(!freqMap[x]) freqMap.erase(x);
        else inverseFreqMap[freqMap[x]].insert(x);

    }
    void remove_inverse_freq(ll num, ll freq){
        inverseFreqMap[freq].erase(num);
        if(inverseFreqMap[freq].empty()) inverseFreqMap.erase(freq);
    }

    ll get_mode(){
        if(freqMap.empty())return -1;
        return *inverseFreqMap.rbegin()->second.begin();
    }
};

struct StreamData{

    Mean mean;
    Median median;
    Mode mode;
    void insert(ll x){
        mean.insert(x);
        median.insert(x);
        mode.insert(x);
    }
    void remove(ll x){
        mean.remove(x);
        median.remove(x);
        mode.remove(x);
    }
    ll get_mode(){
        return mode.get_mode();
    }
    ll get_median(){
        return median.get_median();
    }
    ll get_mean(){
        return mean.getMean();
    }

};

void solve(){

    int q; cin >> q;
    StreamData sd;
    while(q--){
        string s;
        cin >> s;
        if(s=="insert"){
            ll x; cin >> x;
            sd.insert(x);
        }
        else if(s=="remove"){
            ll x; cin >> x;
            sd.remove(x);
        }
        else if(s=="getMean"){
            cout << sd.get_mean() << "\n";
        }
        else if(s=="getMedian"){
            cout << sd.get_median() << "\n";
        }
        else{
            cout << sd.get_mode() << "\n";
        }
    }

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