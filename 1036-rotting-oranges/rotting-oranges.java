class Pair {
    int a, b;

    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<Pair> q = new LinkedList<>();
        int oranges = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2) {
                    q.offer(new Pair(i, j));
                } else if (grid[i][j] == 1) {
                    oranges++;
                }
            }
        }
        if (oranges == 0)
            return 0;
        if (q.isEmpty())
            return -1;
        int[] u = { -1, 0, 1, 0 };
        int[] v = { 0, -1, 0, 1 };
        int ans = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            if (oranges == 0)
                    break;
            for (int k = 0; k < sz; k++) {
                Pair temp = q.poll();
                int x = temp.a, y = temp.b;
                for (int i = 0; i < 4; i++) {
                    int currx = u[i] + x;
                    int curry = v[i] + y;
                    if (currx >= 0 && curry >= 0 && currx < grid.length && curry < grid[0].length
                            && grid[currx][curry] == 1) {
                        grid[currx][curry] = 2;
                        oranges--;
                        q.offer(new Pair(currx, curry));
                    }
                }
            }
            ans++;
        }
        return oranges>0 ? -1 : ans;
    }
}