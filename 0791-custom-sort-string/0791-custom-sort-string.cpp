class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        vector<int> hash(26,-1);
        vector<pair<char,int>> hash2(26);
        string temp = "";
       for(int i=0;i<order.size();i++){
           hash[order[i]-'a'] = i;
       }
        for(int i=0;i<s.size();i++){
            int x = hash[s[i]-'a'];
            if(x==-1){
                temp.push_back(s[i]);
            }else{
                
            hash2[x].first = s[i];
            hash2[x].second+=1;   
            }
           
            
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<hash2[i].second;j++){
                ans.push_back(hash2[i].first);
            }
        }
        
        string finalans = ans.append(temp);
        return finalans;
        
    }
};