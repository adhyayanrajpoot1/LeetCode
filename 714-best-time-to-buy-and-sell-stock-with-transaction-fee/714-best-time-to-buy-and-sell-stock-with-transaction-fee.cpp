class Solution {
public:
    // int dp[100000][2];
    // int f(int i , int fee , int buy , vector<int>&prices)
    // {
    //     if(i>=prices.size())return 0;
    //     if(dp[i][buy]!=-1)return dp[i][buy];
    //     if(buy)
    //     {
    //         return dp[i][buy] = max(-prices[i]+f(i+1,fee,!buy , prices),f(i+1,fee,buy , prices));
    //     }
    //     else
    //     {
    //         return dp[i][buy] = max(prices[i]-fee+f(i+1,fee,!buy,prices),f(i+1,fee,buy,prices));
    //     }
    // }
    int maxProfit(vector<int>& prices, int fee) {
        //memset(dp,-1,sizeof dp);
        int n = prices.size();
        // return f(0,fee,1,prices);
        int cash = 0;
        int hold = -prices[0];
        for(int i = 1 ; i < n ; i++)
        {
            cash = max(cash,hold+prices[i]-fee);
            hold = max(hold , cash-prices[i]);
        }
        return cash;
        
        
        
    }
};