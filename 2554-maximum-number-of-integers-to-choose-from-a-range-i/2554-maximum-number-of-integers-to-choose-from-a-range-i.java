class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        int sum = 0;
        int cnt = 0;
        Set<Integer> hs = new HashSet<>();
    for (int num : banned) {
        hs.add(num);
    }
        for(int i=1;i<=n;i++){ 
            if(!hs.contains(i)){
                if(sum+i>maxSum){ 
                    return cnt;
                }else{
                    sum+=i;
                    cnt++;
                }
            }
        }
        return cnt;
    }
}