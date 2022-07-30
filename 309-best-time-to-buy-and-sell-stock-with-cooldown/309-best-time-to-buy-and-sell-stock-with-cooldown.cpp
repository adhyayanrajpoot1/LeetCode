

class Solution {
public:
    int dp[5001][3];
    int f(int i ,int buy, vector<int>&v)
    {
        if(i>=v.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy)
        {
            return dp[i][buy] = max(-v[i]+f(i+1,!buy,v),f(i+1,buy,v));
        }
        else{
            return dp[i][buy] = max(max(v[i]+f(i+2,!buy,v),f(i+2,buy,v)),max(f(i+1,buy,v),f(i+1,buy,v)));
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        int n = prices.size();
        if(n<2)return 0;
        return f(0,1,prices);
    }
};