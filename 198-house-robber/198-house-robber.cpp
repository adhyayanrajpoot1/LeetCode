class Solution {
public:
    int memo[101];
    int f(int ind , vector<int>& nums)
    {
        if(ind==0)return nums[ind];
        if(ind==1)return max(nums[ind-1],nums[ind]);
        int &ans = memo[ind];
        if(ans!=-1)return ans;
        
        return ans = max(f(ind-2,nums)+nums[ind],f(ind-1,nums));
    }
    int rob(vector<int>& nums) {
        //if(nums.size()==1 || nums.size()==2)return nums[nums.size()-1];
        memset(memo,-1,sizeof(memo));
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i =2 ; i< n ; i++)
        {
            dp[i] = max(dp[i-2]+nums[i] , dp[i-1]);
        }
        return dp[n-1];
        
        
        
        
        
        
        
        
        
        //return f(nums.size()-1,nums);
    }
};