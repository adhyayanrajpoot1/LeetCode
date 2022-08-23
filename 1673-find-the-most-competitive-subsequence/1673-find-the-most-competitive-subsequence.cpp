class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        int count = n-k;
        for(int i = 0 ; i < n ; i++)
        {
            while(ans.size() && count && ans.back()>nums[i])
            {
                ans.pop_back();
                count--;
            }
            ans.push_back(nums[i]);
        }
        while(count)
        {
            ans.pop_back();
            count--;
        }
        return ans;
    }
};