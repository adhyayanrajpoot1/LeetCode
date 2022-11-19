class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int pf = intervals[0][0];
        int ps = intervals[0][1];
        vector<vector<int>>ans;
        for(int i = 0 ; i < intervals.size() ; i++)
        {
            if(intervals[i][0]<=ps)
            {
                ps = max(intervals[i][1] , ps);
            }
            else
            {
                vector<int>temp;
                temp.push_back(pf);
                temp.push_back(ps);
                ans.push_back(temp);
                pf = intervals[i][0];
                ps = intervals[i][1];
            }
        }
        vector<int>temp;
        temp.push_back(pf);
        temp.push_back(ps);
        ans.push_back(temp);
       
        
        return ans;
        
        
    }
};