class Solution {
    public void solve(List<String> ans, StringBuilder temp, int lc, int rc){
        if(lc<0 || rc<0) return;
        if(lc==0 && rc==0){
            ans.add(temp.toString());
            return;
        }
        if(lc < rc){
            temp.append('(');
            solve(ans,temp, lc-1, rc);
            temp.deleteCharAt(temp.length()-1);
            temp.append(')');
            solve(ans,temp, lc, rc-1);
            temp.deleteCharAt(temp.length()-1);
        }else{
            temp.append('(');
            solve(ans,temp, lc-1, rc);
            temp.deleteCharAt(temp.length()-1);
        }
        return;
    }

    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<String>();
        StringBuilder temp = new StringBuilder();
        solve(ans, temp, n , n);
        return ans;
    }
}