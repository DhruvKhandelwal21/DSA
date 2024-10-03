class Solution
{
    public:
       	// int solve(string bw, string ew, unordered_set<string> st){
       	//     if(bw==ew) return 1;
       	//     int ans = 1e8;
       	//     string temp = bw;
       	//     for(int i=0;i < temp.size();i++){
       	//         for(int j=0;j < 26;j++){
       	//             if(j+'a'!=temp[i]){
       	//                 temp[i] = j+'a';
       	//                 if(st.count(temp)){
       	//                     st.erase(temp);
       	//                    ans = min(ans, 1+solve(temp,ew,st));
       	//                     st.insert(temp);
       	//                 }
       	//                  temp[i] = bw[i];
       	//             }
       	//         }
       	//     }
       	//     return ans;
       	// }
        int ladderLength(string beginWord, string endWord, vector<string> &wordList)
        {
            unordered_set<string> st;
            for (auto it: wordList) st.insert(it);
            if (!st.count(endWord)) return 0;
            queue<string> q;
            q.push(beginWord);
            int cnt = 1;
            while (!q.empty())
            {
                int n = q.size();
                for (int k = 0; k < n; k++)
                {
                    string curr = q.front();
                    q.pop();
                    string temp = curr;
                    st.erase(curr);
                    if (curr == endWord) return cnt;
                    for (int i = 0; i < temp.size(); i++)
                    {
                        for (int j = 0; j < 26; j++)
                        {
                            if (j + 'a' != temp[i])
                            {
                                temp[i] = j + 'a';
                                if (st.count(temp))
                                {
                                    q.push(temp);
                                }
                                temp[i] = curr[i];
                            }
                        }
                    }
                }
                cnt++;
            }
           	// int ans = solve(beginWord, endWord, st);
            return 0;
        }
};