#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

int n,m; 
bool board[100][100];

vector<vector<ii>> pairs = {
    {{-1,-1},{-1,0},{0,-1}},
    {{-1, 1},{-1,0},{0, 1}},

    {{ 1,-1},{ 1,0},{0,-1}},
    {{ 1, 1},{ 1,0},{0, 1}}
};


bool check(int row, int col){
    for (int i = 0; i < 4; ++i) {
        bool skip = false;
        int one = 0;
        for (int j = 0; j<3 && !skip; ++j) {
            auto p = pairs[i][j];
            int x=row+p.first, 
                y=col+p.second;
            if(x>=0 && x<n && y>=0 && y<m ){
                one+=board[x][y];
            }
            else{
                skip=true;
            }
        }
        if(one==3) return false;
        if(skip) continue;
    }
    return true;
}
void solve(){
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j){
            board[i][j] = (s[j]=='1');
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){
            if(!board[i][j] && !check(i,j)){
                cout << "No\n";
                return;
            }
        }
    }

    cout << "YES\n";
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();

    return 0;
}
