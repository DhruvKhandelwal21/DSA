class Solution {
public:
    // dp solution
    int dp[1005];
    int solve(int power, int score, vector<int>&token, int i, int l){
        int n= token.size();
        if(i> l)
            return score;
        
        int maxscore= 0;
        //use token
        if(dp[i]!=-1) return dp[i];
        
        if(token[i] <= power){
            maxscore= solve(power- token[i], score+1, token, i+1, l);
            return dp[i]= maxscore= max(score+1, maxscore);
        }
        
        if(score>=1){
            maxscore= solve(power+ token[l], score-1, token, i, l-1);
            return dp[i]= maxscore= max(score-1, maxscore);
        }
        
        //skip
        return dp[i]= solve(power, score, token, i+1, l);
        
    }
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        if(tokens.size()==0||power<tokens[0]) return 0;
        int score = 0;
        int ans = 0;
        int i=0,j=n-1;
        while(i<=j){
            // if(i==0){
            //     score++;
            //     power-=tokens[0];
            //     ans = max(score,ans);
            //     i++; 
            // }
            if(power>=tokens[i]){
                    power-=tokens[i];
                    score++;  
                    ans = max(score,ans);
                    i++;
            }else if(power>=tokens[j]){
                power-=tokens[j];
                    score++;  
                    ans = max(score,ans);
                    j--;
            }else if(score>=1){
                    power+=tokens[j];
                    score--; 
                ans = max(score,ans);
                j--;
            }
        }
        
        return ans;
        // memset(dp, -1, sizeof(dp));
        // int n= tokens.size();
        // sort(tokens.begin(), tokens.end());
        // return solve(power, 0, tokens, 0, n-1);
    }
};