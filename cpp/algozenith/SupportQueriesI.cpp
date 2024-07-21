
#include <bits/stdc++.h>
using namespace std;

struct structure{

    map<long long,long long> freqMap;
    long long sum=0;

    void add(long long x){
        freqMap[x]++;
        sum+=x;
    }
    void remove(long long x){
        auto temp = freqMap.find(x);
        if(temp!=freqMap.end()) {
            sum-=x;
            temp->second--;
            if(temp->second==0) freqMap.erase(temp->first);
        }
    }

    void print_min(){
        if(freqMap.empty()){
            cout << "-1" << "\n";
            return;
        }
        cout << freqMap.begin()->first << "\n";
    }

    void print_max(){
        if(freqMap.empty()){
            cout << "-1" << "\n";
            return;
        }
        cout << freqMap.rbegin()->first << "\n";
    }
    void print_sum() {
        cout << sum << "\n";
    }


};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    structure s;
    int n;
    cin >> n;

    while(n--){
        int x, t;
        char y;
        cin >> t;
        if (t == 1) {
            cin >> x;
            s.add(x);
        } else if (t == 2) {
            cin >> x;
            s.remove(x);
        } else if (t == 3) {
            cin >> y;
            s.print_min();
        } else if (t == 4) {
            cin >> y;
            s.print_max();
        } else if (t == 5) {
            cin >> y;
            s.print_sum();
        }
    }

}