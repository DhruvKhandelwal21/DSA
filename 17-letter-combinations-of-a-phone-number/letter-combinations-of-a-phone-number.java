class Solution {
    void solve(String digits, HashMap<Integer,List<Character>> map, List<String> ans, StringBuilder temp, int idx){
        if(idx>=digits.length()){
            ans.add(temp.toString());
            return;
        }
        int digit = digits.charAt(idx) - '0';
        List<Character> hash = map.get(digit);
        for(int i=0;i<hash.size();i++){
            temp.append(hash.get(i));
            solve(digits, map, ans, temp, idx+1);
            temp.deleteCharAt(temp.length() - 1);
        }
        return;
    }
    public List<String> letterCombinations(String digits) {
        HashMap<Integer,List<Character>> map = new HashMap<>();
        map.put(2, Arrays.asList('a', 'b', 'c'));
        map.put(3, Arrays.asList('d', 'e', 'f'));
        map.put(4, Arrays.asList('g', 'h', 'i'));
        map.put(5, Arrays.asList('j','k','l'));
        map.put(6, Arrays.asList('m','n','o'));
        map.put(7, Arrays.asList('p','q','r','s'));
        map.put(8, Arrays.asList('t','u','v'));
        map.put(9, Arrays.asList('w','x','y','z'));
        List<String> ans = new ArrayList<>();
        StringBuilder temp = new StringBuilder();
        if(digits.length()==0) return ans;
        solve(digits, map, ans,temp, 0);
        return ans;
    }
}