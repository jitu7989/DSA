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

void solve(){

    ll n; cin >> n;
    ll arr[n];

    ll minus1count = 0;
    ll plus1count = 0;

    vector<ii> v(2);

    v[0].first=0;
    v[0].second=0;
    v[1].first=0;
    v[1].second=0;

    ll minus1 = 0;
    ll plus1 = 0;

    ll special=-1;
    ll x = 0;
    ll sum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];

        if(arr[i]==-1){
            minus1++;
            plus1=0;
        }
        else if(arr[i]==1){
            minus1=0;
            plus1++;
        }
        else{
            minus1=0;
            plus1=0;

            for (int j = 0; j < i; ++j) {
                v[x].first    = min(sum,v[x].first);
                v[x].second   = max(sum,v[x].second);
                sum-=arr[j];
            }
            v[x].first    = min(sum,v[x].first);
            v[x].second   = max(sum,v[x].second);

            special=arr[i];
            x++;
        }

        minus1count = max(minus1,minus1count);
        plus1count  = max(plus1 ,plus1count);

        minus1count = max(abs(sum),minus1count);
        plus1count  = max(sum ,plus1count);

        if (x) {
            v[x].first  = min(sum,v[x].first);
            v[x].second = max(sum,v[x].second);
        }
        if (abs(arr[i])==1) sum += arr[i];

    }
    if (x && abs(arr[n-1])==1) {
        v[x].first  = min(sum,v[x].first);
        v[x].second = max(sum,v[x].second);
    }
    minus1count = -(minus1count);

    if(x ){

        ll a = special+(v[0].first+v[1].first);
        ll b = special+(v[0].second+v[1].second);

       if( (minus1count<=a && a<=plus1count) ||  (minus1count<=b && b<=plus1count) ) {
            cout << (max(b,plus1count)-min(a,minus1count)+1) << '\n';
            for(int i=min(a,minus1count); i<=max(b,plus1count); i++){
                cout << i << ' ';
            }
            cout << '\n';
            return;
       }
       else{
            cout << (plus1count-minus1count+1)+(b-a+1) << '\n';
            for(int i=min(a,minus1count); i<=min(b,plus1count); i++){
                cout << i << ' ';
            }
            for(int i=max(a,minus1count); i<=max(b,plus1count); i++){
                cout << i << ' ';
            }
           cout << '\n';
            return;
       }
    }
    else{
            cout << (plus1count-minus1count+1) << '\n';
            for(int i=minus1count; i<=plus1count; i++){
                cout << i << ' ';
            }
            cout << '\n';
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