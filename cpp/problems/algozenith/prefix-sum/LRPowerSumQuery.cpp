#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int N = 1000002;

ll A[N];
ll B[N];

ll powerK1[N];
ll powerK2[N];
ll arr[N];
ll preFix1[N];
ll prefix2[N];



class ModUtil{
public:
    using ll = long long;
    ll mod = 1e9+7;
    ll mul(ll a, ll b){
        return do_mod((a%mod)*(b%mod));
    }
    ll add(ll a,ll b){
        return do_mod((a%mod)+(b%mod));
    }
    ll power(ll n,ll p){
        int ans = 1;
        while(p){
            if(p%2==0){
                n = mul(n,n);
                p/=2;
            }
            else{
                ans = mul(ans,n);
                --p;
            }
        }
        return ans;
    }

    ll divide(ll a,ll b){
        return mul(a, power(b,mod-2));
    }
    ll subtract(ll a,ll b){
        return (((a-b)%mod)+mod)%mod;
    }
    ll do_mod(ll a){
        return ((a%mod)+mod)%mod;
    }
};
ModUtil mod_util;
ll power(ll x,ll y)
{
    ll res = 1;
    while(y)
    {
        if(y&1)
            res = (res*x)%mod;
        y=y/2,x=(x*x)%mod;
    }
    return res%mod;
}

int main(){



    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill(A,A+N,0);
    fill(B,B+N,0);
    fill(arr,arr+N,0);
    fill(preFix1,preFix1+N,0);
    fill(prefix2,prefix2+N,0);
    fill(powerK1,powerK1+N,1);
    fill(powerK2,powerK2+N,1);

    int n,q,k; cin >> n >> q >> k;


    for(int i=1;i<N;i++){
        powerK1[i] = k*powerK1[i-1]%mod;
        powerK2[i] = mod_util.mul(k,powerK2[i-1]);
    }


    for(int i=1; i<=n; i++)  {
        cin >> A[i];
        arr[i] = A[i];
    }
    for (int i = 1; i <= n; ++i){
        arr[i] = arr[i]*powerK1[i]%mod; if(arr[i]<0) arr[i]+=mod;
        B[i] = mod_util.mul(A[i],powerK2[i]);
        if(arr[i]!=B[i]){
            cout << "A[i]*KPower[i]  Not Same\n";
        }
    }

    for (int i = 1; i <= n; ++i)  {
        preFix1[i] = preFix1[i-1]+arr[i];
        if(preFix1[i]>=mod) preFix1[i]-=mod;

        prefix2[i] = mod_util.do_mod(mod_util.add(prefix2[i-1],B[i]));

        if(preFix1[i]!=prefix2[i]){
            cout << " PreFix1 Not Same\n";
        }


    }

    for(int i=1; i<=q; i++){
        int l,r;
        cin >> l >> r;
        long long constant  = mod_util.do_mod(mod_util.power(powerK2[l],mod-2));
        long long sum = mod_util.subtract(prefix2[r],prefix2[l-1]);
        ll ans1 = mod_util.do_mod(mod_util.mul(sum,constant));

        ll ans2 = preFix1[r]-preFix1[l-1]; if(ans2<0) ans2+=mod;
        ans2 = ans2*power(powerK1[l],mod-2)%mod;

        if(ans1!=ans2){
            cout << " Ans Not Same\n";
        }
        cout<<ans1 <<'\n';
    }
    return 0;
}