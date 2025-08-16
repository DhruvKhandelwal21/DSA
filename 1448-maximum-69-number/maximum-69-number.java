class Solution {
    public int maximum69Number (int num) {
        String str = String.valueOf(num);
        StringBuilder ans = new StringBuilder();
        int firstSixFlag = 0;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if(ch=='6' && firstSixFlag==0){
                ans.append(9);
                firstSixFlag = 1;
                continue;
            }
            ans.append(ch);
        }
        int newans = Integer.parseInt(ans.toString());
        return newans;
    }
}