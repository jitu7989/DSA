#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);



    int a,b;
    int x,y;

    cin >> a >> b >> x >> y;


    if ((a<=x && x<=b ) || (x<=a && a<=y) ) {
        int l = min(a,x);
        int r = max(b,y);
        cout << (r-l) << '\n';
    }
    else {
        cout << ((b-a)+(y-x)) << '\n';
    }

}
