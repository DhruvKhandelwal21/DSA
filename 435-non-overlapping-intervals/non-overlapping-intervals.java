class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            } else {
                return Integer.compare(a[0], b[0]);
            }
        });
        int ans = 0;
        int n = intervals.length;
        int maxEnd = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < maxEnd) {
                maxEnd = Math.min(maxEnd, intervals[i][1]);
                ans++;
            } else {
                maxEnd = intervals[i][1];
            }
        }
        return ans;
    }
}