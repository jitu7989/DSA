#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        stack<map<string, int>> stack;
        map<string, int> init;
        stack.push(init);

        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                map<string, int> map;
                stack.push(map);
                i++;
            }
            else if (s[i] == ')') {
                i++;
                int num=0; while (i < n && isdigit(s[i])) num = (num*10)+(s[i++]-'0');
                if(num==0) num = 1;
                auto toAdd       = stack.top(); stack.pop();
                auto &toBeAddedIn = stack.top();
                for (const auto &item: toAdd){
                    auto it = toBeAddedIn.find(item.first);
                    int val = item.second*num;
                    if(it!=toBeAddedIn.end()){
                        it->second+=val;
                    }
                    else{
                        toBeAddedIn.insert({item.first,val});
                    }
                }
            }
            else if (isupper(s[i])) {

                string element(1,s[i++]); while(i<n && islower(s[i])) element+=s[i++];

                int num=0; while (i < n && isdigit(s[i])) num = (num*10)+(s[i++]-'0');
                if(num==0) num = 1;

                auto &toBeAddedIn = stack.top();
                auto it = toBeAddedIn.find(element);
                if(it!=toBeAddedIn.end()){
                    it->second+=num;
                }
                else{
                    toBeAddedIn.insert({element,num});
                }

            }
        }

        string ans;
        auto &freq = stack.top();
        for (const auto &item: freq){
            ans+=item.first;
            if(item.second>1) ans+= to_string(item.second);
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.countOfAtoms("Mg(OH)2") << "\n";
    cout << s.countOfAtoms("K4(ON(SO3)2)2") << "\n";
}