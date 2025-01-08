class Solution {
    public String customSortString(String order, String s) {
        StringBuilder sb = new StringBuilder();
        int[] hash = new int[26];
        Arrays.fill(hash, 0);
        for (int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            hash[idx]++;
        }
        for (int i = 0; i < order.length(); i++) {
            int idx = order.charAt(i) - 'a';
            if (hash[idx] > 0) {
                for (int j = 0; j < hash[idx]; j++) {
                    sb.append(order.charAt(i));
                }
                hash[idx] = 0;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] > 0) {
                char x = (char) (i + 'a');
                for (int j = 0; j < hash[i]; j++) {
                    sb.append(x);
                }
            }
        }
        return sb.toString();
    }
}