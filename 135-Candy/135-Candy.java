class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int ans = n, i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            int peak = 0;
            while (ratings[i] > ratings[i - 1]) {
                i++;
                peak++;
                ans += peak;
                if (i == n)
                    return ans;
            }

            int dip = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                i++;
                dip++;
                ans += dip;
            }
            ans -= Math.min(peak, dip);
            if (i == n)
                return ans;
        }
        return ans;
    }
}