class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
         int n = points.size();
        sort(points.begin(),points.end());
        reverse(points.begin(),points.end());
        int ans = 0;
        
        for(int i=0;i<n-1;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(y2>=y1 || x2==x1){
                    // if(n==2){
                    //     ans++;
                    //     break;
                    // }
                    bool flag = true;
                    
                    for(int k=0;k<n;k++){
                        int x = points[k][0];
                        int y = points[k][1];
                        if((x==x1&&y==y1)||(x==x2&&y==y2)){
                            continue;
                        }else{
                            if(x2<=x&&x<=x1&&y>=y1&&y<=y2){
                                cout<<"hello"<<endl;
                                flag = false;
                                break;
                            }
                            if(x==x1&&x==x2){
                                if(y>=y2&&y<=y1){
                                    flag = false;
                                    break;
                                }
                            }
                        }
                    }
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};