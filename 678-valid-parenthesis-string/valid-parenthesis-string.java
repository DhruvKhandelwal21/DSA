class Solution {
    public boolean checkValidString(String s) {
        int mn = 0, mx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                mn++;
                mx++;
            } else if (s.charAt(i) == '*') {
                mn = mn - 1;
                mx++;
            } else {
                mn = mn - 1;
                mx--;
            }
            if (mn < 0){
                mn = 0;
            }
            if (mx < 0) {
                return false;
            }
        }
        return mn == 0;
    }
}