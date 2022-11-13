class Solution {
public:
    vector<vector<int>>ans;
    void f(int ind , int sum , int tar , vector<int>&ds , vector<int>&nums)
    {
        if(tar<sum)return;
        if(sum==tar)
        {
            ans.push_back(ds);
            return;
        }
        if(ind==nums.size())return;
        ds.push_back(nums[ind]);
        sum+=nums[ind];
        f(ind+1,sum,tar,ds,nums);
        ds.pop_back();
        sum-=nums[ind];
        while( ind+1<nums.size() && nums[ind]==nums[ind+1])ind++;
        f(ind+1,sum,tar,ds,nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(0,0,target,temp,candidates);
        return ans;
    }
};