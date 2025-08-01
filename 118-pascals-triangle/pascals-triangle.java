class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> prev = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            List<Integer> curr = new ArrayList<>();
            if(i==0){
                curr.add(1);
            }else {
                curr.add(1);
                for(int j=1;j<prev.size();j++){
                    curr.add(prev.get(j)+prev.get(j-1));
                }
                curr.add(1);
            }
            prev = curr;
            ans.add(curr);
            curr = new ArrayList<>();
        }   
        return ans;
    }
}