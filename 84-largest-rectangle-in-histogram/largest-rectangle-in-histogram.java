class Pair {
    int first;
    int second;
    Pair(int first, int second){
        this.first = first;
        this.second = second;
    } 
}
class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        ArrayList<Integer> nsl = new ArrayList<>();
        ArrayList<Integer> nsr = new ArrayList<>();
        Stack<Pair> st = new Stack<>();

        for(int i=n-1;i>=0;i--){
           if(st.isEmpty()){
            nsr.add(n);
           }else{
            while(!st.isEmpty() && heights[i]<=st.peek().first){
                st.pop();
            }
            if(st.isEmpty()){
                nsr.add(n);
            }else{
                nsr.add(st.peek().second);
            }
           }
           st.push(new Pair(heights[i], i));
        }
        Collections.reverse(nsr);
        st.clear();
        for(int i=0;i<n;i++){
           if(st.isEmpty()){
            nsl.add(-1);
           }else{
            while(!st.isEmpty() && heights[i]<=st.peek().first){
                st.pop();
            }
            if(st.isEmpty()){
                nsl.add(-1);
            }else{
                nsl.add(st.peek().second);
            }
           }
           st.push(new Pair(heights[i], i));
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            System.out.println(nsr.get(i)+ " " + nsl.get(i));
            int temp = heights[i]*(nsr.get(i)-nsl.get(i)-1);
            ans = Math.max(ans, temp);
        }
        return ans;

    }
}