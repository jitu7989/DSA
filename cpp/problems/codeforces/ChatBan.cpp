#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<int,char>;
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
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
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


bool comp(ii &a, ii &b){
    if(a.second==b.second) 
        return a.first<b.first;
    return a.second<b.second;
}

ll k,x;
ll sum_of_emotes_in_each_tri;
ll message_in_each_tri;


bool check(ll mid){


    if(mid>k){
        ll emotes = (k*(k+1))/2;
        mid-=k;
        
        ll to_remove_mesages = ((k-1)-mid);
        
        ll other_side_emotes = k*(k-1)/2LL;
        ll to_remove_emotes = (to_remove_mesages*(to_remove_mesages+1))/2;
        emotes+=(other_side_emotes-to_remove_emotes);
        return emotes>=x;
    }
    else{
        ll emotes = mid*(mid+1)/2;
        return emotes>=x;
    }
}

void solve(){
    cin >> k >> x;
    
    sum_of_emotes_in_each_tri = (k*(k-1))+k;
    message_in_each_tri       = (2*k)-1;



    ll temp = message_in_each_tri*(x/sum_of_emotes_in_each_tri);
    x -= (x/sum_of_emotes_in_each_tri)*sum_of_emotes_in_each_tri;

    if(temp){
        cout << message_in_each_tri << "\n";
        return;
    }
    ll low = 1, high = message_in_each_tri;
    ll ans = 0;
    while(low<=high && x){
        
        ll mid = (low+high)/2LL;
        if(check(mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << temp+ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
    return 0;
}