class Solution {
    public int numberOfPairs(int[][] points) {
        int res = 0;
        Arrays.sort(points, (a,b) -> {
            if(a[0]!=b[0]) return Integer.compare(a[0],b[0]);
            return Integer.compare(b[1],a[1]);
        });
        int n = points.length;
        for(int i=0;i<n;i++){
            int top = points[i][1];
            int bot = Integer.MIN_VALUE;
            for(int j=i+1;j<n;j++){
                int y = points[j][1];
                if(bot<y && y<=top){
                    res++;
                    bot = y;
                }
            }
        }
        // for(int i=0;i<points.length;i++){
        //     for(int j=0;j<points.length;j++){
        //         if(i==j) continue;
        //         if(goodCouple(i, j, points)) res++;
        //     }
        // }
        return res;
    }
}