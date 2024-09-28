class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> v(n,0);
        v.push_back(m);
        int j=m-1;
        for(int i=n-1;i>=0;i--){
            v[i] = v[i+1];
            if(j>=0 && word1[i]==word2[j]){
                v[i] = j;
                j--;
            }
        }
        j = 0;
        int swapPt = -1;
// We have to find our earliest swap point to get the lexographically smallest seq.
// In 'v' array we have stored the indices that we have matched till now from rear end of the array.
// Now we have to start matching the characters in both strings and increment value of j. There will be a point when characters won't match and we will check that if we swap this character we will get our sequence. 
// 'v' array also tells us the no. of characters that need to be matched from front to get our sequence at that particular index.
// that's why the condition when word1[i]!=word2[j] ==> we check j+1(including swap char) >= v[i+1]
        for(int i=0;i<n;i++){
            if(word1[i]==word2[j]){
                j++;
            }else if(v[i+1]<=j+1){
                 swapPt = j;
                 break;
            }
        }
        int i=0;
        j=0;
        vector<int> ans;
        while(i<n && j<m){
            if(j==swapPt){
                ans.push_back(i);
                j++;
            }else if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            i++;
        }
        return ans.size()<m ? vector<int>(0) : ans;
    }
};