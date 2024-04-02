class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string temp = to_string(x);
        int sum = 0;
        for(auto it:temp){
            sum+=it-'0';
        }
        if(x%sum==0) return sum;
        return -1;
    }
};