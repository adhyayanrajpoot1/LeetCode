class Solution {
public:
    int memo[1001][2][201];
    int dp(int ind ,int k , bool buy , vector<int>& prices)
    {
        if(ind==prices.size())return 0;
        //not buying and selling
        if(memo[ind][buy][k]!=-1)return memo[ind][buy][k];
        int ans = dp(ind+1 ,k , buy , prices);
        
        if(k==0)return 0;
        // buying
        
        if(buy)
            ans = max(ans ,-prices[ind] + dp(ind+1 , k , false , prices));
        else
            ans = max(ans,prices[ind]+dp(ind+1,k-1 , true,prices));
        return memo[ind][buy][k] = ans;
        
        
        
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(memo,-1,sizeof(memo));
         return dp(0,k,true,prices);
    }
};