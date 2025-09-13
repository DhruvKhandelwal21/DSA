class Solution {
    public int maxFreqSum(String s) {
        HashMap<Character, Integer> map1 = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char x = s.charAt(i);
            if (x == 'a' || x == 'i' || x == 'e' || x == 'o' || x == 'u') {
                map1.put(x, map1.getOrDefault(x, 0) + 1);
            } else {
                map2.put(x, map2.getOrDefault(x, 0) + 1);
            }
        }
        int mx1 = 0, mx2 = 0;
        for (Integer value : map1.values()) {
            mx1 = Math.max(value, mx1);
        }
        for (Integer value : map2.values()) {
            mx2 = Math.max(value, mx2);
        }
        return mx1 + mx2;
    }
}