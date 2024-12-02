class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String temp = "";
        int idx = 0;
        for(int i=0;i<sentence.length();i++){
            if(sentence.charAt(i)==' '){
                idx++;
                temp="";
                continue;
            }
            temp+=sentence.charAt(i);
            if(temp.equals(searchWord)) return idx+1;
        }
        return -1;
    }
}