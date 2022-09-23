class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b)
    {
        if(a[1]<b[1])return true;
        if(a[1]==b[1])return a[0]<b[0];
        return false;
    }
    int maxEvents(vector<vector<int>>& events) {
        set<int>s;
        sort(events.begin() , events.end(),cmp);
        int maxi = events[events.size()-1][1];
        for(int i = 1 ; i <= maxi ; i++)
        {
            s.insert(i);
        }
        int res=0;
        for(auto &it : events)
        {
            int st = it[0];
            int e = it[1];
            auto iter = s.lower_bound(st);
            if(iter==s.end() || *iter>e)continue;
            else
            {
                res++;
                s.erase(iter);
            }
        }
        return res;
    }
};