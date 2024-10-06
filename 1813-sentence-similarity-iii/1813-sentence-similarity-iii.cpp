class Solution {
public:
    vector<string> helper(string s){
        vector<string> ans;
         string temp = "";
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp.push_back(s[i]);
            }else{
                ans.push_back(temp);
                temp = "";
            }
        }
        ans.push_back(temp);
        return ans;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        vector<string> ls, ss;
        if(sentence1.size()>sentence2.size()){
            ls = helper(sentence1);
            ss = helper(sentence2);
        }else{
            ss = helper(sentence1);
            ls = helper(sentence2);
        }
        int i=0, j = ls.size()-1;
        int k = 0, l = ss.size()-1;
        while((i<=j) && (k<=l)){
            if(ls[i]==ss[i]){
                i++;
                k++;
            }else if(ls[j]==ss[l]){
                j--;
                l--;
            }else {
                return false;
            }
        }
        
        
    return true;
    }
};