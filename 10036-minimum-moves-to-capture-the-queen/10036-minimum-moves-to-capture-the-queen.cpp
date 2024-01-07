class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e||b==f){
            if(a==c){
                if((d>b&&d<f)||(d>f&&d<b)) return 2;
            }
            if(b==d){
               if((c>a&&e>c)|| (a>c&&c>e)) return 2; 
            }
            
            return 1;
        }
        cout<<"hello"<<endl;
        if(abs(c-e)==abs(d-f)){
            if(abs(c-a)==abs(b-d)){
                if((a>c&&a<e)||(a<c&&a>e)){
                    return 2;
                }
            }
           return 1;
        }
        return 2;
    }
};