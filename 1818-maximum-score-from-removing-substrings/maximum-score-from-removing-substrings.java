class Solution {
    public int maximumGain(String s, int x, int y) {
        int cnt = 0;
        char remove, insert;
        int mx, mn;
        if(x < y){
            remove = 'a';
            insert = 'b';
            mn = x;
            mx = y;
        }else{
            remove = 'b';
            insert = 'a';
            mn = y;
            mx = x;
        }
        StringBuilder stack = new StringBuilder();
        for(char c: s.toCharArray()){
            if(stack.length() > 0 && c==remove && stack.charAt(stack.length()-1) == insert){
                stack.deleteCharAt(stack.length()-1);
                cnt+=mx;
            }else{
                stack.append(c);
            }
        }
        StringBuilder stackSec = new StringBuilder();
        for(int i=0;i<stack.length();i++){
            char c = stack.charAt(i);
            if(stackSec.length() > 0 && c == insert && stackSec.charAt(stackSec.length()-1)==remove){
                stackSec.deleteCharAt(stackSec.length()-1);
                cnt+=mn;
            }else{
                stackSec.append(c);
            }
        }
        return cnt;
    }
}