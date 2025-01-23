class Pair {
    int first;
    int second;
    public Pair(int f, int s){
        this.first = f;
        this.second = s;
    }
}
class StockSpanner {
    Stack<Pair> st;
    public StockSpanner() {
        st = new Stack<>();
    }
    
    public int next(int price) {
        int cnt = 1;
        while(!st.isEmpty() && price>=st.peek().first){
            cnt+=st.peek().second;
            st.pop();
        }
        st.push(new Pair(price, cnt));
        return cnt;
        // if(st.isEmpty()){
        //     st.push(price);
        // }else{
        //   while(!st.isEmpty() && st.peek()<=price){
        //     cnt++;
        //     st.pop();
        //   }
        //   st.push(price);
        // }
        // return cnt;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */