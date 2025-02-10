class Solution {
    public String clearDigits(String s) {
       StringBuilder op = new StringBuilder();
       int digitCnt = 0;
        for(int i=s.length()-1;i>=0;i--){
            char x = s.charAt(i);
            if(x>=97 && x<=122){
               if(digitCnt>0) digitCnt--;
               else op.append(x);
            }else{
                digitCnt++;
            }
        }
  
       return op.reverse().toString();
    }
}