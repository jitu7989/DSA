#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

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


struct CompareG {
    bool operator()(int const& a, int const& b) {
        return a > b;
    }
};
struct CompareS {
    bool operator()(int const& a, int const& b) {
        return a < b;
    }
};
class MedianFinder {
public:

    int size;
    priority_queue<int, vector<int>, CompareG> l;
    priority_queue<int, vector<int>, CompareS> r;

    MedianFinder() {
    }
    void rebalance(){
        while(r.size()>l.size()){
            l.push(r.top());
            r.pop();
        }
        while(l.size()>(r.size()+1)){
            r.push(l.top());
            l.pop();
        }
    }
    void addNum(int num) {
        size++;
        if(l.empty()){
            l.push(num);
            return;
        }
        if(l.top()>=num) l.push(num);
        else r.push(num);
        cout << "UNBALANCE: \n";
        print();
        rebalance();
        cout << "REBALANCE: \n";
        print();
    }
    void print(){
        stack<int> vec;
        cout << "l: ";
        while(!l.empty()){
            vec.push(l.top());
            l.pop();
            cout << vec.top() << ' ';
        }
        cout << '\n';
        while(!vec.empty()){
            l.push(vec.top());
            vec.pop();
        }


        cout << "r: ";
        while(!r.empty()){
            vec.push(r.top());
            r.pop();
            cout << vec.top() << ' ';
        }
        cout << '\n';
        while(!vec.empty()){
            r.push(vec.top());
            vec.pop();
        }

    }
    double findMedian() {
        cout << l.top() << " " << (r.empty()?0:r.top()) << '\n';
        if(size&1){
            return l.top();
        }
        else{
            return (l.top()+r.top())/2.0;
        }
    }
};


signed main(){


    return 0;
}