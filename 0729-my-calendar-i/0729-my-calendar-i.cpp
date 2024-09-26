class MyCalendar {
public:
    vector<pair<int,int>> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int n = cal.size();
        if(cal.size()==0){
            cal.push_back({start, end});
            return true;
        } else if(cal[0].first>=end){
            cal.insert(cal.begin(),{start,end});
            return true;
        } else if(cal[n-1].second<=start){
            cal.push_back({start, end});
            return true;
        }else {
           for(int i=1;i<cal.size();i++){
            int st = cal[i-1].second;
            int en = cal[i].first;
            if(start>=st && end<=en){
                cal.push_back({start,end});
                sort(cal.begin(),cal.end());
                return true;
            } 
          } 
        }
     return false;   
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */