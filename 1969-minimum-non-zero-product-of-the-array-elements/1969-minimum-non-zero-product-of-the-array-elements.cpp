 typedef long long int ll;

class Solution {
    int mod = 1e9 + 7;
public:
    ll solve(ll x,ll n){
    if(n==0){
    return 1;
    }
    if(n%2==0) return solve((x*x)%mod,n/2)%mod;
    else return ((x%mod)*solve(((x%mod)*(x%mod))%mod,(n-1)/2)%mod)%mod;
    }
    int minNonZeroProduct(int p) {
        ll x = (1ll << p) -1;
        return ((x%mod)*solve(x-1,x/2))%mod;
    }
};