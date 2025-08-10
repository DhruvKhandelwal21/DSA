class Solution {
    public int buildUniqueNum(int n){
        int sum = 0;
        while(n>0){
            int x = n%10;
            sum+=Math.pow(10,x);
            n = n/10;
        }
        return sum;
    }
    public boolean reorderedPowerOf2(int n) {
        int target = buildUniqueNum(n);
        for(int i=0;i<=29;i++){
            int temp = buildUniqueNum(1<<i);
            if(temp==target) return true;
        }
        return false;
    }
}