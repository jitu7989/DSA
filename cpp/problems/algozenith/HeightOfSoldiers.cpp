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


    int n; cin>>n;
    int arr[n+2];
    int ans[n+2];
    int pse[n+2],nse[n+2];
    fill(ans,ans+(n+2),0);
    pse[n+1]=0,nse[n+1]=0;
    stack<int> ps,ns;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    arr[0]   = -1e9;
    arr[n+1] = 1e9;

    for (int i = 1,j=n; i <= n; i++,j--) {
        while(!ps.empty() && arr[i]<=arr[ps.top()]) ps.pop();
        if(!ps.empty()) pse[i] = i-ps.top();
        else pse[i] = i;
        ps.push(i);

        while(!ns.empty() && arr[j]<=arr[ns.top()]) ns.pop();
        if(!ns.empty()) nse[j] = ns.top()-j-1;
        else nse[j] = n-j;
        ns.push(j);
    }
    for (int i = 1; i <= n; ++i) {
        int x = pse[i]+nse[i];
        ans[x] = max(arr[i],ans[x]);
    }
    for (int i = n; i >= 1; --i) {
        ans[i] = max(ans[i],ans[i+1]);
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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