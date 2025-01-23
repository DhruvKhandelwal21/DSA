class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(' || s.charAt(i)=='[' || s.charAt(i)=='{'){
                st.push(s.charAt(i));
            }else{
                if(st.isEmpty()) return false;
                char x = st.peek();
                char y = s.charAt(i);
                if((x=='(' && y==')') || (x=='{' && y=='}') || (x=='[' && y==']')){
                    st.pop();
                }else{
                    return false;
                }
            }
      }
      if(!st.isEmpty()) return false;
      return true;
    }
}