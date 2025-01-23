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


void printBinary(ll x) {
    for (int i = 31; i >= 0; i++) {
        if (x & (1 << i)) cout << 1;
        else cout << 0;
    }
}

long long elementThreeTimesExpectOne(vector<ll> &nums) {
    int n = nums.size();
    ll ans = 0;
    for (int i = 0; i < 32; i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) sum += ((nums[j] >> i) & 1);
        ans |= ((sum % 3 != 0) << i);
    }
    return ans;
}

int everyElementOccursEvenNumberOfTimeExpectOne(vector<ll> &nums) {
    int n = nums.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) ans ^= nums[i];
    return ans;
}

int everElementOccursEvenNumberOfTimeExpectTwo(vector<ll> &nums) {
    int a = 0, b = 0;
    int n = nums.size();
    int x = 0;
    for (int i = 0; i < nums.size(); ++i) {
        x^=nums[i];
    }

    int cnt = 0;
    while (x>0) {
        if (x&1) break;
        x = x>>1;
        cnt++;
    }
    cnt = 1<<cnt;
    for (int i = 0; i < n; ++i) {
        if (cnt&nums[i]){
            a ^= nums[i];
        }
        else {
            b ^= nums[i];
        }
    }
    cout << a << " " << b << '\n';
}

int findXorFrom1TOn(int n) {
    // 1 = 0001  =  1
    // 2 = 0010  =  3
    // 3 = 0011  =  0
    // 4 = 0100  =  4
    // 5 = 0101  =  1
    // 6 = 0110  =  7
    // 7 = 0111  =  0
    // 8 = 1000  =  8

    if (n % 4 == 0) return 1;
    else if (n % 4 == 2) return n + 1;
    else if (n % 4 == 3) return 0;
    else return n;
}

void oneNumberMissingFrom1ToN(vector<ll> &nums, int n) {
    ll ans = 0;
    for (ll i = 1; i <= n; i++) ans ^= i;
    for (ll i = 0; i < nums.size(); i++) ans = ans ^ nums[i];
    cout << ans << '\n';
}


int givenAndArrayGetXorOfAllSubarray(vector<ll> &nums) {
    /*
    Question 7 Given an array of integers, find the xor of elements of all the subarrays possible.
       Example:
       {12,15,6,7,9,14,18} => 17
       {2,5,6,8,7,12} => 0
     */
    int n = nums.size();
    int x = 0;
    for (int i = 0; i < n; ++i) {
        int freq = (i+1)*(n-i);
        if(freq&1) x ^= nums[i];
    }
    return x;
}

long long number_of_posi_bits_differ(vector<ll> &nums) {
    /*
       Question 8 Suppose f(X,Y) = number of positions in binary representation where bits differ. Given an array of integers, find the sum of f(a_i,a_j) for every possible i and j in range 1 to n. Find answer modulo 10^9+7.
         Example:
         {2, 3, 7, 6, 4} => 32
         {1,5,12,7,14,16} => 76
     */
    int n = nums.size();
    long long mod = 1e9+7;
    long long x = 0;
    for (int i = 0; i < 31; ++i) {
        long long freq[2];
        long long pow = 1LL<<i;
        for (int j = 0; j < n; ++j) {
            freq[(pow&nums[j])%2]++;
        }
        x = (x+((freq[0]*freq[1])%mod))%mod;
    }

    return (x+x)%mod;
}

ll find_pair_lowest_integer(vector<ll> &nums) {
    /*Question 9 Given an array of integers, find the minimum xor of a pair of elements of the array.
        Example:
        {2, 3, 7, 6, 4} => 1
        {2, 5, 4, 2, 6, 8, 9} => 0
     */
    int n = nums.size();
    sort(nums.begin(),nums.end());
    ll res = 1e9;
    for (int i = 1; i < n; ++i) {
        res = min(res,nums[i-1]^nums[i]);
    }
    return res;
}

/* TODO:
       Question 6 Given a positive integer n, find the count of positive integers i such that 0 <= i <= n and n+i=n^i.
       Example:
            10 => 4
            18 => 8
        -----------------------------------------------------
       Question 10 Find the total number of set bits of all the numbers from 0 to n.
       Example:
       4 => 5
       5 => 7
 */
int main() {
}
















