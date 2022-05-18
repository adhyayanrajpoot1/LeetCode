class Solution {
public:
    int solve(int i , vector<int>& nums,vector<int>&dp)
    {
        if(i==nums.size())return 0;
        if(i==nums.size()-1)return nums[i];
        if(dp[i]!=-1)return dp[i];
       return dp[i] = max(solve(i+1,nums,dp),solve(i+2,nums,dp)+nums[i]);
        
        
        
        
    }
    int solve2(int i , vector<int>& nums , vector<int>&dp)
    {
        int n = nums.size();
        dp[0] = nums[0];
        
        for(int i= 2 ; i <= n ; i++)
        {
            dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
        }
        return dp[n];
        
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};