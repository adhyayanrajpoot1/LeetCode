class Solution {
public:
    void f(int ind , vector<int>&nums ,vector<int>ds , set<vector<int>>&s)
    {
        if(ind==nums.size())
        {
            sort(ds.begin(),ds.end());
            s.insert(ds);
            return;
        }
        
        ds.push_back(nums[ind]);
        f(ind+1,nums,ds,s);
        ds.pop_back();
        f(ind+1,nums,ds,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<vector<int>>ans;
        f(0,nums,{},s);
        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};