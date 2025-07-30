class Solution {
    public void solve(int[] candidates, HashSet<List<Integer>> st, List<Integer> temp, List<List<Integer>> ans, int target, int idx){
        if(idx>=candidates.length){
            if(target==0 && !st.contains(temp)){
                ans.add(new ArrayList<>(temp));
            }
            return;
        }
        if(target>=candidates[idx]){
            target-=candidates[idx];
            temp.add(candidates[idx]);
            solve(candidates, st, temp, ans,target, idx);
            target+=candidates[idx];
            temp.remove(temp.size()-1);
        }
        solve(candidates, st, temp, ans,target, idx+1);
        return;

    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        HashSet<List<Integer>> st = new HashSet<>();
        List<Integer> temp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        solve(candidates, st, temp, ans, target, 0);
        return ans; 
    }
}