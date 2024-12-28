class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        int i = 0, n = intervals.length;
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.add(intervals[i]);
            i++;
        }
        System.out.println(i);
        while (i < n && ( intervals[i][0]<=newInterval[1])) {
            int x = Math.min(newInterval[0], intervals[i][0]);
            int y = Math.max(newInterval[1], intervals[i][1]);
            newInterval[0] = x;
            newInterval[1] = y;
            i++;
        }
        ans.add(newInterval);
        while (i < n && newInterval[1]<intervals[i][0]) {
            ans.add(intervals[i]);
            i++;
        }
        return ans.toArray(new int[ans.size()][]);
    }
}