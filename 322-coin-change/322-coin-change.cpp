class Solution {
public:
    int solve(int ind , int amount,vector<int>& coins,vector<vector<int>>&res)
    {
        if(ind==0){
            if(amount%coins[ind]==0)return amount/coins[ind];
            else return 1e7;
        }
        int &ans = res[ind][amount];
        if(ans!=-1)return ans;
        int pick = 1e7;
        if(coins[ind]<=amount)
        {
            pick = 1+solve(ind,amount-coins[ind],coins,res);
        }
        int nonPick = solve(ind-1,amount,coins,res);
        return ans= min(pick,nonPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>res(n+1,vector<int>(amount+1,-1));
        int ans =  solve(coins.size()-1 , amount,coins,res);
        if(ans>=1e7)return -1;
        return ans;
    }
};