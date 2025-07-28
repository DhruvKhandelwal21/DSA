class Solution {
    public void solve(int[] nums, int idx, List<List<Integer>> ans, HashSet<List<Integer>> st, List<Integer> temp){
        if(idx>=nums.length){
            if(!st.contains(temp)){
            ans.add(new ArrayList<>(temp));
            st.add(new ArrayList<>(temp));
            }
            return;
        }
        temp.add(nums[idx]);
        solve(nums, idx+1, ans, st, temp);
        temp.remove(temp.size() - 1);
        solve(nums, idx+1, ans, st, temp);
        return;
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        HashSet<List<Integer>> st = new HashSet<>();
        List<Integer> temp = new ArrayList<>(); 
        solve(nums,0,ans, st, temp);
        return ans;
    }
}