// User function Template for Java

class Solution {
    public static void solve(List<String> ans, StringBuilder temp, int n){
        if(n==0){
          String tempAns = temp.toString();
          ans.add(tempAns);
          return;
        }
        int len = temp.length();
        if(len > 0 && temp.charAt(len-1)=='1'){
            temp.append('0');
            solve(ans,temp,n-1);
            temp.deleteCharAt(temp.length() - 1);
            return;
        }
        temp.append('0');
        solve(ans,temp,n-1);
        temp.deleteCharAt(temp.length() - 1);
        temp.append('1');
        solve(ans,temp,n-1);
        temp.deleteCharAt(temp.length() - 1);
        return;
    }
    public static List<String> generateBinaryStrings(int n) {
        StringBuilder temp = new StringBuilder();
        List<String> ans = new ArrayList<>();
        solve(ans,temp,n);
        return ans;
    }
}
