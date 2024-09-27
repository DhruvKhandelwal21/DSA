class MyCalendarTwo {
public:
    vector<pair<int,int>> reserve;
    unordered_map<int,int> mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        if(reserve.size()==0){
            reserve.push_back({start, end});
        }else{
            bool check = true;
            for(int i=0;i<reserve.size();i++){
                int st = reserve[i].first;
                int ed = reserve[i].second;
                if(max(start,st)<min(ed,end)){
                    if(check){
                      for(auto it: mp){
                        int mst = it.first;
                        int mnd = it.second;
                        if(max(start,mst)<min(mnd,end)){
                            return false;
                    }
                }  
            }
             check = false;      
             mp[max(start,st)] = min(ed,end);
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