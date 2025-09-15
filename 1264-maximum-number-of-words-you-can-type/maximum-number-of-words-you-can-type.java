class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        HashSet<Character> st = new HashSet<>();
        for(int i=0;i<brokenLetters.length();i++){
            char x = brokenLetters.charAt(i);
            st.add(x);
        }
        int ans = 0;
        boolean skip = false;
        boolean alreadyCounted = false;
        for(int i=0;i<text.length();i++){
            char x = text.charAt(i);
            if(x==' '){
                if(skip){
                    skip = false;
                }else{
                    ans++;
                    continue;
                }
            }
            if(st.contains(x)){
                skip = true;
            }
        }
        if(!skip) ans++;
        return ans;
    }
}