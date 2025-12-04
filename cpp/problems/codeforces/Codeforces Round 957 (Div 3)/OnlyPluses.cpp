#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

int get_max(int mx,int a, int b, int c,int num){
    if(num>3){
        return 1;
    }
    int p = 1;
    for (int i = 0; i <= mx ; ++i) {
        if(num==1){
            p = max(p, (a+i)*get_max(mx-i,a,b,c,num+1));
        }
        else if(num==2){
            p = max(p, (b+i)*get_max(mx-i,a,b,c,num+1));
        }
        else if(num==3){
            p = max(p, (c+i)*get_max(mx-i,a,b,c,num+1));
        }
    }
    return p;
}

void solve(){

    int a,b,c;
    cin >> a >> b >>c;
    cout << get_max(5,a,b,c,1) << "\n";
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}