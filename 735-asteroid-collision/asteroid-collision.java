class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        int n = asteroids.length;
        List<Integer> ans = new ArrayList<>();
        for(int i=n-1;i>=0;i--){
            if(asteroids[i]<0){
                st.push(asteroids[i]);
            }else{
                while(!st.isEmpty() && Math.abs(st.peek()) < asteroids[i]){
                    st.pop();
                }
                if(st.isEmpty()){
                    ans.add(asteroids[i]);
                }else if(Math.abs(st.peek())==asteroids[i]){
                    st.pop();
                }
            }
        }
        List<Integer> finalAns = new ArrayList<>();
        if(!st.isEmpty()){
            while(!st.isEmpty()){
                finalAns.add(st.peek());
                st.pop();
            }
        }
        for(int i=ans.size()-1;i>=0;i--){
        finalAns.add(ans.get(i));
        }

        return finalAns.stream().mapToInt(Integer::intValue).toArray();
    }
}