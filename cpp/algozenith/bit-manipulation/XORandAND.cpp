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
ll mod = 1000000007LL;
ll power_of_two[100001];

ll add (ll a,ll b) {
    return (((a%mod)+(b%mod))+mod)%mod;
}
void solve(){

    int n; cin >> n;
    vector<ll> arr = vector<ll>(n);
    for (int i = 0; i < n; ++i)  cin >> arr[i];

    ll sum_of_xor_of_pairs = 0;
    ll sum_of_and_of_pairs = 0;
    ll sum_of_xor_of_all_subsets = 0;
    ll sum_of_and_of_all_subsets = 0;
    for (int i=0; i<=31; i++) {

        ll ith_pow = (1LL<<i);
        ll cnt[2]; cnt[0]=0; cnt[1]=0;
        for (int idx = 0; idx < n; ++idx) {
            cnt[(arr[idx]&(1LL<<i))!=0]++;
        }
        sum_of_xor_of_pairs = add(sum_of_xor_of_pairs,((ith_pow*(cnt[0]*cnt[1]))%mod));
        sum_of_and_of_pairs = add(sum_of_and_of_pairs,((ith_pow*(((cnt[1]*(cnt[1]-1LL))/2LL)))%mod));

        if (cnt[1])
            sum_of_xor_of_all_subsets = add(sum_of_xor_of_all_subsets,ith_pow*power_of_two[n-1]%mod);

        sum_of_and_of_all_subsets = add(sum_of_and_of_all_subsets,ith_pow*(power_of_two[cnt[1]]-1LL+mod)%mod);

    }

    cout << sum_of_xor_of_pairs       << ' ' <<
            sum_of_xor_of_all_subsets << ' ' <<
            sum_of_and_of_pairs       << ' ' <<
            sum_of_and_of_all_subsets << ' ' <<   '\n';

}

// 989098    → 000000000011110000101110001010
// 987656790 → 000111010101100010101111010110
// 989098765 → 111010101100010111100011001101
// 234543    → 000000000000111001010010001111
// 3456543   → 000000001101001110010010011111
// 234567543 → 001110000010110010110000010111
// 1234567   → 000000000100101101011010000111
// 5678      → 000000000000000001011000101110
// 56789     → 000000000000001101110110110101
// 8909876   → 000000100010000011110011110100



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    power_of_two[0] = 1;
    for (int i = 1; i < 100001; ++i)
        power_of_two[i] = add(power_of_two[i-1],power_of_two[i-1]);
    int tc;
    cin >> tc;
    while(tc--) solve();

    return 0;
}