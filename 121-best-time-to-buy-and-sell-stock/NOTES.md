if(buy)  //if we are buying then next time we will sell else next time we will buy
{        //-prices[i], because bought stock of prices[i], expend money
return v[i][buy]=max(-prices[i]+find(prices,i+1,k,!buy,v),find(prices,i+1,k,buy,v));
}
else    //it's time to sell , now decrease k, we have done 1 transaction
{       //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
return v[i][buy]=max( prices[i]+find(prices,i+1,k-1,!buy,v),find(prices,i+1,k,buy,v));
}
}
int maxProfit(vector<int>& prices) {
int n=prices.size();
vector<vector<int>> v(n,vector<int> (2,-1));
//passing here buy=1 because we will first buy then sell
//we can do atmost k=1 transaction
return find(prices,0,1,1,v);
}
};
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
​
You can do as many transactions as you like
​
class Solution {
public:
int find(int ind,vector<int> &v,bool buy,vector<vector<int>> &memo)
{
if(ind>=v.size()) return 0;
if(memo[ind][buy]!=-1) return memo[ind][buy];
if(buy) //if we are buying then next time we will sell else next time we will buy
{      //-prices[i], because bought stock of prices[i], expend money, !buy because next time sell
return memo[ind][buy]=max(-v[ind]+find(ind+1,v,!buy,memo),find(ind+1,v,buy,memo));
}
else   //it's time to sell
{      //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
return memo[ind][buy]=max(v[ind]+find(ind+1,v,!buy,memo),find(ind+1,v,buy,memo));
}
}
int maxProfit(vector<int>& prices) {
int n=prices.size();
if(n<2) return 0;