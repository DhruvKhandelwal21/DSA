class Solution {

    public boolean canChange(String source, String target) {
        int n = source.length(), m = target.length();
        int i = 0, j = 0;
        if (source.equals(target)) {
            return true;
        }
       while(i<n && j<m){
           if(source.charAt(i)==target.charAt(j)){
               if(source.charAt(i)=='R' && i>j){
                   return false;
               }else if(source.charAt(i)=='L' && i<j){
                   return false;
               }else{
                   i++;
                   j++;
               }
           }else{
               if(source.charAt(i)=='_'){
                   i++;
               }else if(target.charAt(j)=='_'){
                   j++;
               }else{
                   return false;
               }
           }
       }
        
        if(i<n){
            while(i<n){
                if(source.charAt(i)!='_') return false;
                i++;
            }
        }
        if(j<m){
            while(j<m){
                if(target.charAt(j)!='_') return false;
                j++;
            }
        }
        return true;
    }
}
