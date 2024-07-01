#include <bits/stdc++.h>;
using namespace std;

int mod = 1e9+7;

int bin_pow(int a,int b,int mod){
    if(b==0) return 1;
    if(b==1) return a;
    int pow = bin_pow(a,b/2,mod);
    return (((pow*pow)%mod)*(b&1?a:1))%mod;
}
int main(){
    int a = 10;
    int b = 3;

//    calculate (a/b)%mod
    cout << bin_pow(b,mod-2,mod)*a%mod;

}