#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;


bool solve(){

    int n,m,k;
    string s;

    cin >> n >> m >> k;
    cin >> s;
    if(m>n){
        return true;
    }
    vector<char> path(n+2);
    vector<bool> canReach(n+2, false);
    vector<int> freez(n+2,0);

    path[0] = 'L';
    path[n+1] = 'L';
    canReach[0] = true;
    freez[0] = k;

    for (int i = 1; i <= n ; ++i) {
        path[i] = s[i-1];
    }

    for (int i = 0; i <= n; ++i) {
        if(!canReach[i]) continue;
        int toDie = freez[i];
        if(toDie==0 && path[i]=='W'){
            continue;
        }
        if(path[i]=='L'){
            int j = i+1;
            while(j<=(n+1) && j<=(i+m) ){
                if(j==n+1) return true;

                if(path[j]=='W'){
                    freez[j] = max(freez[j],toDie);
                    canReach[j]  = true;
                }
                else if(path[j]=='L'){
                    freez[j] = max(freez[j],toDie);
                    canReach[j] = true;
                }
                j++;
            }
        }
        else if(path[i]=='W'){
            int j = i+1;
            int dying = toDie;
            while( !canReach[j] && dying ){
                if(j==n+1) return true;
                if(path[j]=='W'){
                    canReach[j] = true;
                    freez[j] = max(--dying,freez[j]);
                }
                else if(path[j]=='L'){
                    canReach[j] = true;
                    freez[j] = max(--dying,freez[j]);
                    break;
                }
                else {
                    break;
                }
                j++;
            }
        }
    }
    return canReach[n+1];
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) cout << (solve() ? "YES": "NO") << "\n";

}