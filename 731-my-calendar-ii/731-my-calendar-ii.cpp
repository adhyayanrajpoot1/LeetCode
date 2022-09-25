class MyCalendarTwo {
public:
    vector<pair<int,int>>events,doubleBooking;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto &it : doubleBooking)
        {
            if(start<it.second && end>it.first)return false;
        }
        for(auto &it : events)
        {
            if(start<it.second && end>it.first)
            {
                doubleBooking.push_back({max(start,it.first),min(it.second,end)});
            }
        }
        events.push_back({start,end});
        return true;
        
    }
};





// class MyCalendarTwo {
// public:
//     map<int,int>m;
//     MyCalendarTwo() {
        
//     }
    
//     bool book(int start, int end) {
//         m[start]++;
//         m[end]--;
//         int sum =0;
//         for(auto &it : m)
//         {
//             sum+=it.second;
//             if(sum>=3)
//             {
//                 m[start]--;
//                 m[end]++;
//                 return false;
//             }
//         }
//         return true;
//     }
// };

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */