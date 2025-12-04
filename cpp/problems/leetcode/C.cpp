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

class ExamTracker {
public:
    ExamTracker() {}

    map<int,long long> timeScoreMap;
    void record(int time, int score) {
        long long finalVal = score;
        if (!timeScoreMap.empty()) {
            auto end_val = timeScoreMap.rbegin();
            finalVal+=end_val->second;
        }
        timeScoreMap[time] = finalVal;
    }

    long long totalScore(int startTime, int endTime) {
        auto it =  timeScoreMap.lower_bound(startTime);
        if (it == timeScoreMap.end() || it->first>endTime) return 0;
        long long score_to_minus = 0;
        if (it!=timeScoreMap.begin()) {
            it--;
            score_to_minus = it->second;
        }
        auto ite = timeScoreMap.lower_bound(endTime+1);
        ite--;
        return ite->second-score_to_minus;
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /**
         ["ExamTracker","record","totalScore","record","totalScore","totalScore","totalScore","totalScore"]
         [[],[1,98],[1,1],[5,99],[1,3],[1,5],[3,4],[2,5]]

         ["ExamTracker","record","record","record","record","record","totalScore"]
         [[],[],[],[],[],[],[]]©leetcode
     */

    ExamTracker exam_tracker_1;

    exam_tracker_1.record(1,98);
    cout << "exam_tracker_1: " << exam_tracker_1.totalScore(1,1) << '\n';
    exam_tracker_1.record(5,99);
    cout << "exam_tracker_1: " << exam_tracker_1.totalScore(1,3) << '\n';
    cout << "exam_tracker_1: " << exam_tracker_1.totalScore(1,5) << '\n';
    cout << "exam_tracker_1: " << exam_tracker_1.totalScore(3,4) << '\n';
    cout << "exam_tracker_1: " << exam_tracker_1.totalScore(2,5) << '\n';

    ExamTracker exam_tracker_2;
    exam_tracker_2.record(999999996,999999996);
    exam_tracker_2.record(999999997,999999997);
    exam_tracker_2.record(999999998,999999998);
    exam_tracker_2.record(999999999,999999999);
    exam_tracker_2.record(1000000000,1000000000);
    cout << "exam_tracker_2: " << exam_tracker_2.totalScore(1,1000000000) << '\n';

    // ["ExamTracker","record","totalScore","totalScore","totalScore"]
    // [[],[2,2],[1,1],[1,2],[2,2]]
    ExamTracker exam_tracker_3;
    exam_tracker_3.record(2,2);
    cout << "exam_tracker_3: " << exam_tracker_3.totalScore(1,1) << '\n';
    cout << "exam_tracker_3: " << exam_tracker_3.totalScore(1,2) << '\n';
    cout << "exam_tracker_3: " << exam_tracker_3.totalScore(2,2) << '\n';



    return 0;
}