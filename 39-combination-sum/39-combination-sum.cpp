class Solution {
public:
    vector<vector<int>>ans;
    void f(int ind , int sum ,int tar, vector<int>&ds , vector<int>&nums)
    {
        if(sum==tar)
        {
            ans.push_back(ds);
            return;
        }
        if(ind==nums.size())return;
        
       if(nums[ind]+sum<=tar)
       {
            ds.push_back(nums[ind]);
            sum+=nums[ind];
            f(ind,sum,tar,ds,nums);
            ds.pop_back();
            sum-=nums[ind];
       }
        f(ind+1,sum,tar,ds,nums);
        
            
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //vector<vector<int>>ans;
        vector<int>temp;
        f(0,0,target,temp,candidates);
        return ans;
    }
};