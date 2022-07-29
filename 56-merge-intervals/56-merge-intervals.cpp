class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>small = intervals[0];
        for(auto it : intervals)
        {
            if(small[1]>=it[0])
            {
                small[1] = max(small[1],it[1]);
            }
            else{
                ans.push_back(small);
                small = it;
            }
        }
        ans.push_back(small);
        return ans;
    }
};