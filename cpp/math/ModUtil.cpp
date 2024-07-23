class ModUtil{
public:
    using ll = long long;
    ll mod = 1e9+7;
    ll mul(ll a, ll b){
        return ((a%mod)*(b%mod))%mod;
    }
    ll add(ll a,ll b){
        return ((a%mod)+(b%mod))%mod;
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
        return (a-b+mod)%mod;
    }
    ll do_mod(ll a){
        return a%mod;
    }
};