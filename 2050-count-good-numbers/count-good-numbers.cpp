class Solution {
public:
int mod = 1e9 + 7;
    long long int power(long long int k, long long int n ){
        if(n==0) return 1;
        if(n==1) return k;
        if(n%2==0) return power((k*k)%mod,n/2)%mod;
        else return (k*power((k*k)%mod,(n-1)/2))%mod;
    }
    int countGoodNumbers(long long n) {
        long long int odd = n/2;
        long long int even = n/2 + n%2;
        return (power(5,even)*power(4,odd))%mod;
    }
};