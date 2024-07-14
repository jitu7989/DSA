#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string exp) {

        int n = exp.size();
        vector<string> a;
        int i=0;
        set<string> set1 = solve(exp,i,n);
        for (auto item: set1){
            a.push_back(item);
        }
        return a;
    }
    set<string> solve(string exp,int &i,int n) {
        set<string> vec;
        if(i>=n) return vec;
        while(i<n) {

            if (exp[i] == '{') {
                auto x = solve(exp, ++i, n);
                if (vec.empty()) for (const auto &item: x) vec.insert(item);
                else if (!x.empty()) {
                    set<string> multiplied;
                    for (const auto &item1: vec) {
                        for (const auto &item2: x) {
                            multiplied.insert(item1 + item2);
                        }
                    }
                    vec = multiplied;
                }
            }

            while (i < n) {
                string element;
                if (isalpha(exp[i])) {
                    while (i < n && isalpha(exp[i]))element += exp[i++];
                    if(exp[i]=='{'){
                        auto x = solve(exp, ++i, n);
                        for (const auto &item: x) vec.insert(element+item);
                        if(x.empty()) vec.insert(element);
                    }
                    else vec.insert(element);
                }
                if (exp[i] == ',') i++;
                if (exp[i] == '}') {
                    i++;
                    return vec;
                }
            }
        }
        return vec;
    }
};

int main(){
    Solution s;
//    for (const auto &item: s.braceExpansionII("{a,b}{c,{d,e}}")){
//        cout << item << " ";
//    }
//    cout << "\n";
    for (const auto &item: s.braceExpansionII("{a,b}{c,{d,e}}")){
        cout << item << " ";
    }
    cout << "\n";

    for (const auto &item: s.braceExpansionII("{{a,z},a{b,c},{ab,z}}")){
        cout << item << " ";
    }
    cout << "\n";

}