class Solution {
public:
    int f(int ind , int A , vector<int>&coins,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(A%coins[ind]==0)return A/coins[ind];
            return 1e9;
        }
        int&ans = dp[ind][A];
        if(ans!=-1)return ans;
        int pick = 1e9;
        if(coins[ind]<=A)
        {
            pick = 1+ f(ind,A-coins[ind],coins,dp);
        }
        int nonPick = f(ind-1 , A , coins,dp);
        return ans = min(pick,nonPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = f(n-1 , amount , coins,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};