class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        if(nums.size()==0)return 0;
        int maxi = 1;
        for(auto it : nums)
        {
            s.insert(it);
        }
        for(auto it : nums)
        {
            if(s.find(it-1)!=s.end())
            {
                continue;
            }
            else
            {
                int ele = it;
                int len = 0;
                while(s.find(ele)!=s.end())
                {
                    len++;
                    ele = ele+1;
                }
                maxi = max(maxi,len);
            }
        }
        return maxi;
    }
};