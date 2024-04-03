class Solution {
public:
    int sum(vector<int> &stud,vector<int> &ment){
        int score = 0;
        for(int i=0;i<stud.size();i++){
            if(stud[i]==ment[i]){
                score++;
            }
        }
        return score;
    }
    void solve(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int> matchedMentor, int &ans,int curr,int temp,int &n){
        if(curr>=n){
            ans = max(ans,temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(matchedMentor[i]==0){
                int calci = sum(students[curr],mentors[i]);
                matchedMentor[i] = 1;
                solve(students,mentors,matchedMentor,ans,curr+1,temp+calci,n);
                matchedMentor[i] = 0;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = mentors.size();
        vector<int> matchedMentor(n,0);
        int ans = 0;
        solve(students,mentors,matchedMentor,ans,0,0,n);
        return ans;
    }
};