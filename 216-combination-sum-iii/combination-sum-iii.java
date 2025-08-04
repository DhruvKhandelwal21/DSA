class Solution {
    public void solve(List<List<Integer>> result, List<Integer> temp, int idx, int n, int k){
        if(temp.size()==k){
            if(n==0){
                result.add(new ArrayList<>(temp));
            }
            return;
        }
        for(int i = idx;i<10;i++){
            if(n<i) break;
            temp.add(i);
            solve(result, temp, i+1, n-i, k);
            temp.remove(temp.size()-1);
        }
        return;
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        int res = 0;
        List<List<Integer>> result = new ArrayList<>();
        for(int i=1;i<=k;i++){
            res+=i;
        }
        if(res>n) return result;
        List<Integer> temp = new ArrayList<>();
        solve(result, temp, 1, n, k);
        return result;
    }
}