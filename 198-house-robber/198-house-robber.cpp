class Solution {
public:
    int solve(int i , vector<int>& nums,vector<int>&dp)
    {
        if(i==nums.size())return 0;
        if(i==nums.size()-1)return nums[i];
        if(dp[i]!=-1)return dp[i];
       return dp[i] = max(solve(i+1,nums,dp),solve(i+2,nums,dp)+nums[i]);
        
        
        
        
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};