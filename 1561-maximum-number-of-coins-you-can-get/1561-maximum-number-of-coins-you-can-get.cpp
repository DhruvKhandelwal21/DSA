class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        int n = piles.size();
        if(piles.size()==3){
            return piles[1];
        }
        sort(piles.begin(),piles.end());
        int i = 0, j = n-1, k = n-2;
        while(i<k){
            ans+=piles[k];
            i++;
            j-=2;
            k-=2;
        }
        return ans;
    }
};