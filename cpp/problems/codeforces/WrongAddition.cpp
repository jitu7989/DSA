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

ll digit(string a){
    ll pow = 1;
    ll num = 0;
    for (int i = a.length(); i>=1 ; i--){
        num += pow*(a[i-1]-'0');
        pow *= 10;
    }
    return num;
}

ll getB(int i, int j, string x, string z,string y){

    if(i==-1 && j==-1){
        return digit(y);
    }
    if(i==-1){
        string temp((j+1)+y.length(),'0');
        for (int a = 0; a <= j; ++a) temp[a] = z[a];
        for (int a = j+1; a <= temp.length(); ++a){
            temp[a] = y[a-(j+1)];
        }
        return digit(temp);
    }
    if(j==-1){
        return -1;
    }

    ll d1 = x[i]-'0';
    ll d2 = z[j]-'0';
    ll d3 = 0;
    ll ans = -1;

    d3 = d2-d1;
    if(d3>=0){
        y[i] = '0'+d3;
        ans = getB(i-1,j-1,x,z,y);
        y[i] = '0';
    }
    
    if(ans==-1 && j>0){
        ll d4 = d2+(10*(z[j-1]-'0'));
        d3 = d4-d1;
        if(10<=d4 && d4<=18 && 0<=d3 && d3<=9){
            y[i] = '0'+d3;
            ans = max(ans,getB(i-1,j-2,x,z,y));
            y[i] = '0';
        }    
    }
    
    return ans;
}

void solve(){
    ll a,s;
    cin >> a >> s;
    string x=to_string(a), z=to_string(s);
    cout << getB(x.length()-1,z.length()-1,x,z,string(x.length(),0)) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}