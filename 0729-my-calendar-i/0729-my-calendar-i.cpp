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
        } else {
           for(int i=0;i<cal.size();i++){
            int st = cal[i].first;
            int en = cal[i].second;
            if(min(en,end)>max(st,start)){
                return false;
            } 
          }
        }
     cal.push_back({start,end});
     return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */