class Solution {
public:
    void f(int ind , vector<int>&ds , vector<vector<int>>&ans,vector<int>&nums)
    {
        if(ind>nums.size())return;
        if(ind==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        f(ind+1 , ds,ans,nums);
        ds.pop_back();
        f(ind+1,ds,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        f(0,ds,ans,nums);
        return ans;
    }
};