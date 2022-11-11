class Solution {
public:
    void f(int ind , vector<int>&nums , set<vector<int>>&s)
    {
        if(ind==nums.size())
        {
            s.insert(nums);
            return;
        }
        for(int i = ind ; i< nums.size() ; i++)
        {
            swap(nums[i],nums[ind]);
            f(ind+1,nums,s);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        f(0,nums,s);
        vector<vector<int>>ans;
        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};