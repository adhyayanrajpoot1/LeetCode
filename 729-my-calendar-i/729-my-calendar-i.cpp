class MyCalendar {
public:
    // bool *arr = new bool[1e9+5]();
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto it : mp){
            sum+=it.second;
            if(sum>1){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */