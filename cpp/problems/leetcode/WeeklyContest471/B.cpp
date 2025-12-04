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
    int single_longest(const string & string) {
        int ans = 1;
        int head = -1;
        int tail = 0;
        int n = string.size();
        set<int> st;
        while (tail<n) {
            int next_head = head + 1;
            while (next_head<n && (st.find(string[next_head])==st.end()) ){
                head = next_head;
                st.insert(string[next_head]);
                next_head++;
            }
            ans = max(ans,(head-tail+1));
            st.erase(string[tail]);
            tail++;
            if (tail>head) {
                head = tail-1;
            }
        }
        return ans;
    };

    int longestBalanced(string s) {
        int n = s.length();
        vector<vector<int>> arr(n,vector<int>(26));
        vector<vector<int>> alpha_posi(26);
        for(int i=0; i<n; i++){
            fill(arr[i].begin(),arr[i].end(),0);
        }


        for(int i=0; i<n; i++){
            int mapChar = s[i]-'a';
            arr[i][mapChar]++;
            alpha_posi[mapChar].push_back(i);
            if(i>0){
                for(int alhpabet=0; alhpabet<26; alhpabet++) {
                    arr[i][alhpabet] += arr[i-1][alhpabet];
                }
            }
        }

        int ans = single_longest(s);

        for(int start=0; start<n; start++){

            vector<int> curr_alpha_posi =  alpha_posi[s[start]-'a'];

            for (int j = curr_alpha_posi.size()-1; j>=0; j--) {
                if (ans>=(curr_alpha_posi[j]-start+1)) {
                    break;
                }
                int end  = curr_alpha_posi[j];
                set<int> st;
                for(int alhpabet=0; alhpabet<26; alhpabet++){
                    int toAdd = arr[end][alhpabet];
                    if(start>0){
                        toAdd-=arr[start-1][alhpabet];
                    }
                    if(toAdd!=0){
                        st.insert(toAdd);
                    }
                    if(st.size()>1) break;
                }
                if (st.size()==1) {
                    ans = max(ans,end-start+1);
                }
            }
        }

        return ans;
    }
};


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution s;
    cout << "longestBalanced(cc): " << s.longestBalanced("cc") << '\n';
    cout << "longestBalanced(abbac): " << s.longestBalanced("abbac") << '\n';
    cout << "longestBalanced(zzabccy): " << s.longestBalanced("zzabccy") << '\n';
    cout << "longestBalanced(aba): " << s.longestBalanced("aba") << '\n';
    cout << "longestBalanced(aabcc): " << s.longestBalanced("aabcc") << '\n';


    return 0;
}