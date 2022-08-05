class Solution {
public:
    int dp[10000];
    int f(int tar,vector<int>&nums) {
       if(tar==0)return 1;
        if(tar<= 0 )return 0;
        int ans = 0;
        if(dp[tar]!=-1)return dp[tar];
        for(auto it : nums)
        {
            if(tar-it>=0)
                ans+=f(tar-it,nums);
        }
        return dp[tar] = ans;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        return f(target,nums);
        //return ans.size();
    }
};