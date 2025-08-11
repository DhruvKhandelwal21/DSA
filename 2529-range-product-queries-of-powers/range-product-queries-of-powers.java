class Solution {
    public static List<Integer> getSetBitValues(int n) {
        List<Integer> values = new ArrayList<>();
        int bitValue = 1;

        while (n > 0) {
            if ((n & 1) == 1) {
                values.add(bitValue);
            }
            bitValue <<= 1;
            n >>= 1;
        }
        return values;
    }
    int mod = 1_000_000_007;
    public int[] productQueries(int n, int[][] queries) {
        List<Integer> arr = getSetBitValues(n);
        List<Integer> prefix = new ArrayList<>();
        int[] ans = new int[queries.length];
        prefix.add(arr.get(0));
        for(int i=1;i<arr.size();i++){
            prefix.add((arr.get(i)*prefix.get(i-1))%mod);
        }
        System.out.println(prefix);
        for(int i=0;i<queries.length;i++){
            int a = queries[i][0];
            int b = queries[i][1];
            long result = 1;
            for(int j=a;j<=b;j++){
                result = (result*arr.get(j))%mod;
            }
            ans[i] = (int)result;
        }
        return ans; 
    }
}