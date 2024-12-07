class Solution {
    public boolean lemonadeChange(int[] bills) {
     int fi=0, te=0, twe=0;
     for(int it: bills){
         if(it==5){
             fi++;
         }else{
             if(it==10){
                 if(fi>0){
                     fi--;
                     te++;
                 }else{
                     return false;
                 }
             }else if(it==20){
                 if(te>0 && fi>0){
                     te--;
                     fi--;
                     twe++;
                 }else if(fi>=3){
                    fi-=3;
                     twe++;
                 }else{
                     return false;
                 }
                 
             }
         }
     }
        return true;
    }
}