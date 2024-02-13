class Solution {
public:
    bool check(string word){
        int i=0,j=word.size()-1;
        while(i<=j){
            if(word[i]!=word[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            if(check(words[i])) return words[i];
        }
        return "";
    }
};