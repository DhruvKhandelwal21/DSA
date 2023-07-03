class Solution {
public:
    bool checkFreq(string s,string p){
       vector<int> countFreq(26,0);
       for(int i=0;i<s.size();i++){
           countFreq[s[i]-'a']++;
           if(countFreq[s[i]-'a']>1){
               return true;
           }
       }
       return false;
    }
    bool buddyStrings(string s, string goal) {
        int mod1=  0,mod2 = 0;
        int diff = 0;
        int m = s.size();
        int n = goal.size();
        vector<int> temp;
        if(m!=n){
            return false;
        }
        if(s==goal){
            if(checkFreq(s,goal)){
                return true;
            }
            return false;
        }
        for(int i=0;i<m;i++){
           
            if(s[i]==goal[i]){
                continue;
            }else{
                temp.push_back(i);
            }
        }
        if(temp.size()!=2){
            return false;
        }else{
            swap(s[temp[0]],s[temp[1]]);
            if(s!=goal){
                return false;
            }
        }

        return true;
    }
};