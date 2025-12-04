#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int arr[2] = {0,0};
    for(int i=0; i<s.length(); i+=2){
        arr[s[i]!='A']+=(s[i+1]-'0');
    }

    if (arr[0]>arr[1]) {
        cout << 'A';
    }
    else {
        cout << 'B';
    }

    return 0;
}
