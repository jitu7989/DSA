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



struct Median{
    ll sum = 0;
    multiset<ll> topK;
    multiset<ll> later;
    int k;
    void insert(ll x){
        topK.insert(x);
        sum += x;
        if(topK.size()>k){
            sum-=(*topK.begin());
            later.insert(*topK.begin());
            topK.erase(topK.begin());
        }
    }

    void remove(ll x){
        if(later.find(x)!=later.end()){
            later.erase(later.find(x));
        }
        else if(topK.find(x)!=topK.end()){
            sum-=x;
            topK.erase(topK.find(x));
            if(!later.empty()){
                sum+=*later.rbegin();
                topK.insert(*later.rbegin());
                auto it = later.end();it.operator--();
                later.erase(it);
            }
        }
    }

    ll get_median(){
        return sum;
    }
};


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,k;
    cin >> n >> k;
    Median median;
    median.k = k;

    while(n--){
        int a,b;
        char x;
        cin >> a;
        if(a==1){
            cin >> b;
            median.insert(b);
        }
        else if(a==2){
            cin >> b;
            median.remove(b);
        }
        else{
            cin >> x;
            cout << median.get_median() << "\n";
        }
    }

    return 0;
}