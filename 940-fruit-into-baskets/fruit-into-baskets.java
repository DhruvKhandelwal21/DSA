class Solution {
    public int totalFruit(int[] fruits) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int i=0,j=0, n = fruits.length;
        int ans=0, cnt=0;
        while(j<n){
            map.put(fruits[j], map.getOrDefault(fruits[j], 0) + 1);
            if(map.size()>2){
                while(map.size()>2){
                    map.put(fruits[i], map.getOrDefault(fruits[i], 0) - 1);
                    if(map.get(fruits[i])==0){
                        map.remove(fruits[i]);
                    }
                    i++;
                    cnt--;
                }
            }
            cnt++;
            j++;
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}