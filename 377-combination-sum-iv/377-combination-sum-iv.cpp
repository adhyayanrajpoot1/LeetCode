class Solution {
public:
    uint dp[10000];
    int f(int tar,vector<int>&nums) {
       if(tar==0)return 1;
        if(tar<0 )return 0;
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
        memset(dp,0,sizeof dp);
        //return f(target,nums);
        //return ans.size();
        //int ans = 0;
        dp[0] = 1;
        for(int tar = 1; tar <=target ; tar++)
        {
            for(auto it : nums)
            {
                if(tar-it>=0)
                    dp[tar]+=dp[tar-it];
            }
        }
        return dp[target];
    }
};