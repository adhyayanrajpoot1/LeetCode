class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        set<int>s;
        for(int i = 0 ; i < ranges.size() ; i++)
        {
            int l = ranges[i][0];
            int r = ranges[i][1];
            for(int j = l ; j <= r ; j++)
            {
                s.insert(j);
            }
        }
        for(int i = left ; i<=right ; i++)
        {
            if(s.find(i)==s.end())return false;
        }
        return true;
    }
};