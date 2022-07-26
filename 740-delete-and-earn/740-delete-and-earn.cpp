class Solution {
public:
    int dp[100000];
    int f(int ind , vector<int>&points)
    {
        if(ind>=points.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind] = max(f(ind+2,points)+points[ind] , f(ind+1,points));
        
    }
    //similar to house robber
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        vector<int>points(100000,0);
        for(auto it : nums)
        {
            points[it]+=it;
        }
        return f(0,points);
    }
};