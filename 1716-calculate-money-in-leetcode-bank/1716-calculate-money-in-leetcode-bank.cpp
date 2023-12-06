class Solution {
public:
    int solve(int n, int mon){
        if(n==0){
            return 0;
        }
        if(n>7){
            return ((7)*(2*mon + 6))/2 + solve(n-7,mon+1);
        }else{
            cout<<(n/2)*(2*mon + n-1)<<endl;
            return ((n)*(2*mon + n-1))/2 + solve(0,mon+1);
        }
    }
    int totalMoney(int n) {
        return solve(n,1);
    }
};