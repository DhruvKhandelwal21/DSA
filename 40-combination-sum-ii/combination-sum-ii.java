class Solution {
    public void solve(int[] candidates, List<List<Integer>> ans,HashSet<List<Integer>> st, List<Integer> temp, int target, int idx){
        if(idx>=candidates.length){
            if(target==0 && !st.contains(temp)){
                ans.add(new ArrayList<>(temp));
                st.add(new ArrayList<>(temp));
            }
            return;
        }
        if(target>=candidates[idx]){
            temp.add(candidates[idx]);
            solve(candidates, ans, st, temp, target-candidates[idx], idx+1);
            temp.remove(temp.size()-1);
        }
        int next = idx+1;
        while(next<candidates.length && candidates[idx]==candidates[next]) next++;
        solve(candidates, ans, st, temp, target, next);
        return;
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        HashSet<List<Integer>> st = new HashSet<>();
        List<Integer> temp = new ArrayList<>();
        solve(candidates, ans, st, temp, target, 0);
        return ans;
    }
}