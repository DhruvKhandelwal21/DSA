class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {
        int k = conflictingPairs.length;
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for (int i = 0; i <=n; i++) {  // n should be the max possible value of `b`
            arr.add(new ArrayList<>());
        }
        for(int i=0;i<k;i++){
            int a = Math.min(conflictingPairs[i][0], conflictingPairs[i][1]);
            int b = Math.max(conflictingPairs[i][0], conflictingPairs[i][1]);
            arr.get(b).add(a);
        }
        long valid = 0, maxConflict = 0, secMaxConflict = 0;
        long[] extras = new long[n+1];
        Arrays.fill(extras,0);

        for(int i=1;i<=n;i++){
            for(int j=0;j<arr.get(i).size();j++){
                if(arr.get(i).get(j)>=maxConflict){
                    secMaxConflict = maxConflict;
                    maxConflict = arr.get(i).get(j);
                }else if(arr.get(i).get(j) > secMaxConflict){
                    secMaxConflict = arr.get(i).get(j);
                }
            }
            valid+=i-maxConflict;
            extras[(int) maxConflict]+= maxConflict-secMaxConflict;
        }
        long maxExtra = 0;
        for(int i=0;i<extras.length;i++){
            maxExtra = Math.max(extras[i], maxExtra);
        }
        return valid + maxExtra;
    }
}