class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        int temp = 1;
        while(n>=0){
            n-=temp;
            temp++;
            count++;
        }
        if(n<0){
            return count-1;
        }
        return count;
    }
};