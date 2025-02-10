class Solution {
    public String clearDigits(String s) {
        Stack<Character> st = new Stack<>();
        for(int i=0;i<s.length();i++){
            char x = s.charAt(i);
            if(x>=97 && x<=122){
               st.push(x);
            }else if(!st.isEmpty()){
                st.pop();
            }
        }
        StringBuilder op = new StringBuilder();
        while(!st.isEmpty()){
            op.append(st.peek());
            st.pop();
        }
       return op.reverse().toString();
    }
}