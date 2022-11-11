class Solution {
public:
    void f(int ind , vector<int>&nums ,vector<int>ds , vector<vector<int>>&v)
    {
        if(ind==nums.size())
        {
            //sort(ds.begin(),ds.end());
            v.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        f(ind+1,nums,ds,v);
        ds.pop_back();
        while(ind+1 < nums.size() && nums[ind]==nums[ind+1])ind++;
        f(ind+1,nums,ds,v);
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        f(0,nums,{},ans);
        return ans;
    }
};