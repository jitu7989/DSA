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
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int rowFlips = 0;
        int colFlips = 0;
        int totalOnes = 0;

        // Count flips needed to make rows palindromic
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                if (grid[i][j] != grid[i][m - 1 - j]) {
                    rowFlips++;
                }
            }
        }

        // Count flips needed to make columns palindromic
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n / 2; ++i) {
                if (grid[i][j] != grid[n - 1 - i][j]) {
                    colFlips++;
                }
            }
        }

        // Count the total number of 1's in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    totalOnes++;
                }
            }
        }

        // Calculate additional flips needed to make the count of 1's divisible by 4
        int additionalFlips = (4 - (totalOnes % 4)) % 4;

        // Adjust the flips for the count of 1's divisible by 4
        int flipsForOnes = additionalFlips;
        if (additionalFlips == 3) flipsForOnes = 1;

        // Total flips to make rows and columns palindromic
        int totalFlips = rowFlips + colFlips;

        // Return the sum of flips for palindromes and flips to adjust 1's count
        return totalFlips + flipsForOnes;
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> grid1 = {{1,0,0},{0,1,0},{0,0,1}};
    Solution sol;
    cout << sol.minFlips(grid1) << endl; // Output should be 3

    return 0;
}