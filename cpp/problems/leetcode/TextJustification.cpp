#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int temp_size = 0,con_str_sz=0;
        vector<string> ans;
        vector<string*> temp;
        for (int i=0; i<words.size(); ){
            string &item = words[i];
            int n = item.size();
            if(temp_size+n<=maxWidth){
                temp_size+=n;
                temp.push_back(&item);
                con_str_sz+=n;
                if(temp_size!=maxWidth) temp_size++;
                i++;
            }
            else{
                int spaces = maxWidth-con_str_sz;
                int to_add = temp.size()-1;
                string s;
                for (const auto &ti: temp){
                    s+=*ti;
                    if(!to_add) to_add++;
                    int space_size = ceil((double long)spaces/to_add);
                    int space_to_add = min(spaces,space_size);
                    spaces-=space_to_add;
                    for (int j = 0; j < space_to_add; ++j)  s+=' ';
                    to_add--;
                }
                temp.clear();
                temp_size = 0;
                con_str_sz = 0;
                ans.push_back(s);
            }
        }
        if(!temp.empty()){
            int spaces = maxWidth-con_str_sz;
            string s;
            for (const auto &ti: temp){
                s+=*ti;
                if(spaces) {
                    s+=' ';
                    spaces--;
                }
            }
            while(spaces--) s+=' ';
            ans.push_back(s);
        }
        return ans;
    }
};

void solve(vector<string>& words, int maxWidth){
    Solution s;
    for (const auto &item: s.fullJustify(words, 16)){
        cout << item << "|\n";
    };
    cout << "===========================================================" << "\n";
}

int main(){
    vector<string> v1 = { "This", "is", "an", "example", "of", "text", "justification." };
    vector<string> v2 = { "What", "must", "be", "acknowledgment", "shall", "be" };
    vector<string> v3 = { "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
    vector<string> v4 = { "ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    solve(v1,16);
    solve(v2,16);
    solve(v3,20);
    solve(v4,16);
}