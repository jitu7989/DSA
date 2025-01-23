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


int a,b;
vector<int> ten_power = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int numberDigitSize;

int digits(int x){
    int count = 0;
    while(x){
        count++;
        x/=10;
    }
    return count;
}

bool prime(int x){
    for (int i = 2; i*i <= x; ++i)
        if((x%i)==0) return false;
    return true;
}


ll generateDigits(int digit, int num, int currentPower){

    if(digit>numberDigitSize) {
        if(a<=num && num<=b) return prime(num);
        return 0;
    }

    int to_generate_till = ceil(numberDigitSize/2.0);
    ll ans = 0;
    // If half of the digits are not generated generate
    if(digit<=to_generate_till){
        // considering remaining elements from 0 to 9 if chossing 1 digit it should be odd cause prime are always a odd number
        for (int i = 0; i<=9; ++i){
            if((digit==1 && i&1) || digit!=1) {

                int temp = num+(i*ten_power[currentPower]);
                ans += generateDigits(digit+1,temp,currentPower-1);
            }
        }

    }
    // generate other half of the plaindrome number
    else {
        // lets suppose forming a 5 digit prime palindrome then 12300 is generate and other half 21 is to be generated
        int remove_pow = to_generate_till;
        int temp = num/ten_power[remove_pow];
        remove_pow--;
        if(numberDigitSize&1) remove_pow--;
        while(temp){
            int toadd = temp%10;
            num += toadd*ten_power[remove_pow];
            temp/=10;
        }
        ans = generateDigits(numberDigitSize+1,num,-1);
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;

    int y = digits(b);

    ll ans = 0;
    for (int i = digits(a); i <= y; ++i) {
        numberDigitSize = i;
        ans += generateDigits(1,0,i-1);
    }
    cout << ans << '\n';
    return 0;
}