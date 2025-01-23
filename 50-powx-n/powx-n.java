class Solution {
    public double myPow(double x, int n) {
        if(x==0) return 0;
        long k = n<0 ? -1L * n : n;
        System.out.println(-1L * n);
        System.out.println(Math.abs(n));
        double ans = 1;
        while(k>0){
            if(k%2==0){
                x = x*x;
                k = k/2;
            }else{
                ans = ans*x;
                k--;
            }
        }

        return n<0 ? (1.0/ans) : ans;

    }
}