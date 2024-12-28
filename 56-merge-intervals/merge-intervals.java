class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> ans = new ArrayList<>();
        int n = intervals.length;
        int[] currInterval = new int[2];
        currInterval = intervals[0];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= currInterval[1]) {
                currInterval[0] = Math.min(currInterval[0], intervals[i][0]);
                currInterval[1] = Math.max(currInterval[1], intervals[i][1]);
            } else {
                ans.add(currInterval);
                currInterval = intervals[i];
            }
        }
        ans.add(currInterval);
        return ans.toArray(new int[ans.size()][]);
    }
}