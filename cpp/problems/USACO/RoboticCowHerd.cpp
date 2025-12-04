#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("roboherd.in");
    ofstream fout("roboherd.out");
    int n,k;
    fin >> n >> k;

    vector<int> ms(n);
    vector<vector<int>> arrm(n,vector<int>(0));


    for (int i = 0; i < n; ++i) {
        fin >> ms[i];
        int m = ms[i];
        arrm[i].resize(m);
        for (int j = 0; j < m; ++j)  fin >> arrm[i][j];
        sort(arrm[i].begin(), arrm[i].end());



    }






}