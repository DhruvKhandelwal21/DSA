class Solution {
     // private HashSet<Integer> set = new HashSet<>();
    private HashMap<Integer, Integer> map = new HashMap<>();
    public boolean solve(int []stones, int idx, int target, int jump, int [][] dp){
        // if(curr>target) return false;
        if(stones[idx]==target) return true;
        if(dp[idx][jump]!=-1) return dp[idx][jump]==1 ? true : false;
        boolean j1 = false, j2 = false, j3 = false;
        if(jump-1>0 && map.containsKey(stones[idx]+jump-1)){
            int nextIdx = map.get(stones[idx]+jump-1);
            j1 = solve(stones,nextIdx, target, jump-1, dp);
        }
        if(map.containsKey(stones[idx]+jump)){
           int nextIdx = map.get(stones[idx]+jump);
           j2 = solve(stones, nextIdx, target, jump, dp);
        }
        if(map.containsKey(stones[idx]+jump+1)){
            int nextIdx = map.get(stones[idx]+jump+1);
            j3 = solve(stones, nextIdx, target, jump+1, dp);
        }
        dp[idx][jump] = (j1 || j2 || j3) ? 1 : 0;
        return j1 || j2 || j3;
    }
    public boolean canCross(int[] stones) {
       int n = stones.length;
       int target = stones[n-1];
        if(stones[1]!=1) return false;
        int [][] dp = new int[n+1][n+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
       for(int i=0;i<n;i++){
           map.put(stones[i],i);
       }
       return solve(stones,1, target, 1, dp);
    }
}