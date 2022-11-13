class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , cmp);
        if(intervals.size()==1)return 0;
        int prevA = intervals[0][0];
        int prevB = intervals[0][1];
        int c=0;
        for(int i = 1 ; i < intervals.size() ; i++)
        {
            int a = intervals[i][0];
            int b = intervals[i][1];
            if(prevB>a)
            {
                c++;
                continue;
            }
            prevA = a;
            prevB = b;
        }
        return c;
        
    }
};