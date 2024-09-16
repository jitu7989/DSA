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
        return do_mod(a-b);
    }
    ll do_mod(ll a){
        return ((a%mod)+mod)%mod;
    }
    ll inv(ll num,ll pow){
        return power(power(num,pow),mod-2);
    }
    ll inv(ll num){
        return power(num,mod-2);
    }
};