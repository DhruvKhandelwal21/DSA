class Solution {
    public int longestConsecutive(int[] nums) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int num: nums){
            map.put(num,1);
        }
        for(int i=0;i<nums.length;i++){
            if(map.containsKey(nums[i]-1)){
                map.put(nums[i]-1,0);
            }
        }
        int ans = 0;
        for(int key: map.keySet()){
            if(map.get(key)==1){
                int x = key;
                int cnt = 1;
                // System.out.println(x);
                while(map.containsKey(x-1)){
                    cnt++;
                    x--;
                }
                ans = Math.max(ans,cnt);
            }
        }
        return ans;
    }
}