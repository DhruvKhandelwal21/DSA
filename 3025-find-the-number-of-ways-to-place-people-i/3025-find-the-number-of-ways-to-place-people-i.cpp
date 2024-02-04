class Solution {
public:
     static bool comp(vector<int>&a,vector<int>&b) {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),comp);
        reverse(points.begin(),points.end());
        
        for(int i=0;i<n;i++){
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }
        
        int ans = 0;
        
        for(int i=0;i<n-1;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int mx = INT_MAX;
            for(int j=i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(y2<y1) continue;
                if(y2<mx) ans++;
                if(y2<mx) mx = y2;
//                 if(y2>=y1 || x2==x1){
//                     bool flag = true;
                    
//                     for(int k=0;k<n;k++){
//                         int x = points[k][0];
//                         int y = points[k][1];
//                         if((x==x1&&y==y1)||(x==x2&&y==y2)){
//                             continue;
//                         }else{
//                             if(x2<=x&&x<=x1&&y>=y1&&y<=y2){
//                                 cout<<"hello"<<endl;
//                                 flag = false;
//                                 break;
//                             }
//                             if(x==x1&&x==x2){
//                                 if(y>=y2&&y<=y1){
//                                     flag = false;
//                                     break;
//                                 }
//                             }
//                         }
//                     }
//                     if(flag) ans++;
//                 }
            }
        }
        return ans;
    }
};