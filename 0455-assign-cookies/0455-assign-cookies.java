class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int idx = s.length-1;
        int x = g.length;
        int cnt = 0;
        if(idx<0) return 0;
        for(int i = x-1;i>=0;i--){
            if(idx>=0 && s[idx]>=g[i]){
                cnt++;
                idx--;
            }
        }
        return cnt;
    }
}