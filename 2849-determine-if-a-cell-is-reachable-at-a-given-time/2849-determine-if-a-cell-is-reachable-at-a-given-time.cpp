class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int hdist = abs(sy-fy);
        int vdist = abs(sx-fx);
        int ans = max(hdist,vdist);
        if(ans==0) return t!=1;
        if(ans>t) return false;
        return true;
    }
};