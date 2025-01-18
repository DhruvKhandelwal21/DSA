class Pair {
    int first, second;
    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int largestRectangleArea(int[] heights) {
       List<Integer> sml = new ArrayList<>();
       List<Integer> smr = new ArrayList<>();
       Stack<Pair> st = new Stack<>();
       // calculating nearest smallest to left.
       
       for(int i=0;i<heights.length;i++){
         while (!st.isEmpty() && st.peek().first >= heights[i]) {
                st.pop();
            }
            if (st.isEmpty()) {
                sml.add(-1);
            } else {
                sml.add(st.peek().second);
            }
            st.push(new Pair(heights[i], i));
       }
       st.clear();
       // calculating nearest smallest to right.

        for(int i=heights.length-1;i>=0;i--){
           while (!st.isEmpty() && st.peek().first >= heights[i]) {
                st.pop();
            }
            if (st.isEmpty()) {
                smr.add(heights.length);
            } else {
                smr.add(st.peek().second);
            }
            st.push(new Pair(heights[i], i));
       }
       Collections.reverse(smr);
       int ans = 0;
       for(int i=0;i<heights.length;i++){
        int width = smr.get(i)-sml.get(i)-1;
        System.out.println(smr.get(i) + "," + sml.get(i) + "," + heights[i]);
          ans = Math.max(ans, width*heights[i]);
       }
       return ans;
       
    }
}