class Solution {
public:
    // map<pair<double,long long int>,long double> mp;
    // long double solve(double x, long long k){
    //     if(k==0){
    //         return 1;
    //     }
    //     if(mp.find({x, k}) != mp.end()){
    //         return mp[{x,k}];
    //     }
    //     long double ans;
    //     if(k%2==0){
    //         ans = solve(x,k/2)*solve(x,k/2);
    //     }else{
    //         ans = x*solve(x,k/2)*solve(x,k/2);
    //     }
    //     return mp[{x,k}] = ans;
    // }
    double myPow(double x, int n) {
        if(x==0) return 0;
        double ans = 1;
        long long k = abs(n);
        while(k!=0){
            if(k%2==0){
                x = x*x;
                k = k/2;
            }else{
                ans = ans*x;
                k--;
            }
        }
        
        return n<0?double(1/ans):ans;
        
    }
};