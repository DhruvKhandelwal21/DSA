class Solution {
    public boolean doesAliceWin(String s) {
        for(int i=0;i<s.length();i++){
            char x = s.charAt(i);
            if (x == 'a' || x == 'i' || x == 'e' || x == 'o' || x == 'u') {
                return true;
            }
        }
        return false;
    }
}