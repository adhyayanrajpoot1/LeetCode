class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==0 || n==1)return 0;
        int dp[n+1];
        dp[0]=0;
        dp[1] =0;
        dp[2] = min(dp[1]+cost[1], dp[0]+cost[0]);
        for(int i = 3 ; i <= n  ;i++)
        {
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
        
    }
};