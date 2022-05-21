class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i<prices.size();i++)
        {
            mini = min(mini,prices[i]);
            if(prices[i]>mini)
            {
                // profit+=(prices[i+1]-prices[i]);
                int diff = prices[i]-mini;
                maxi = max(diff,maxi);
                
            }
        }
        if(maxi==INT_MIN)return 0;
        return maxi;
    }
};