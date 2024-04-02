class Solution {
public:
    
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int full = numBottles;
        int ans= 0;
        while(full>0){
            empty+=full;
            ans+=full;
            full = 0;
            while(empty>=numExchange){
                empty-=numExchange;
                numExchange++;
                full++;
            }
        }
        return ans;
    }
};