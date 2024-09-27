class MyCalendarTwo {
public:
    vector<pair<int,int>> reserve;
    MyCalendarTwo() {
        
    }
    bool check(int st,int ed){
        int cnt = 0;
        for(int j=0;j<reserve.size();j++){
                    int s = reserve[j].first;
                    int e = reserve[j].second;
                    if(max(s,st)<min(e,ed)){
                        cnt++;
                    }
                }
        if(cnt>=2) return true;
        return false;
    }
    bool book(int start, int end) {
        if(reserve.size()==0){
            reserve.push_back({start, end});
            return true;
        }else{
            for(int i=0;i<reserve.size();i++){
                int st = reserve[i].first;
                int ed = reserve[i].second;
                int x = max(start,st);
                int y = min(ed,end);
                if(x<y){
                if(check(x,y)) return false;   
            }   
        }
    }
reserve.push_back({start, end});
return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */