#include <bits/stdc++.h>;
using namespace std;

long long P[1004][1003];
long long A[1004][1003];
const int mod = 1e9+7;



void init(int n,int m){
    for (int i = 0; i <= n+1; ++i) {
        for (int j = 0; j <= m+1; ++j) {
            if(i==0 || j==0 || i==(n+1) || j==(m+1)){
                continue;
            }
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            P[i][j] = (A[i][j]+P[i - 1][j]+P[i][j - 1]-P[i - 1][j - 1])%mod;
        }
    }

}

void processQuery(){
    int u,l,d,r;
    cin >> u >> l >> d >> r;

    cout << (((P[d][r]-P[d][l-1]-P[u-1][r]+P[u-1][l-1])%mod)+mod)%mod << "\n";

}
void solve(){

    int n,m,q;
    cin >> n >> m >> q;
    init(n,m);
    while(q--){
        processQuery();
    }

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}