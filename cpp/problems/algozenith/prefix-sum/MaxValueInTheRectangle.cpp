#include <bits/stdc++.h>;
using namespace std;

long long P[1003][1003];


void processQuery(int U, int D, int L, int R, int X) {
    P[U][L] += X;
    P[U][R+1] -= X;
    P[D+1][L] -= X;
    P[D+1][R+1] += X;
}
void computePrefixSum(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0) P[i][j] += P[i - 1][j];
            if (j > 0) P[i][j] += P[i][j - 1];
            if (i > 0 && j > 0) P[i][j] -= P[i - 1][j - 1];
        }
    }
}

void init(int n, int m) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            P[i][j]=0;
        }
    }
}

void getMax(int n, int m) {
    long long mx = INT32_MIN;
    long long freq = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(P[i][j] > mx){
                mx = P[i][j];
                freq=1;
            }
            else if(P[i][j] == mx){
                freq++;
            }

        }
    }
    cout << mx << " " << freq << "\n";
}

void processQuery(){
    int u,l,d,r,c;
    cin >> u >> l >> d >> r >> c;
    processQuery(u,d,l,r,c);
}
void solve(){

    int n,m,q;
    cin >> n >> m >> q;
    init(n+2,m+2);
    while(q--){
        processQuery();
    }
    computePrefixSum(n,m);
    getMax(n,m);

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}