class Solution {
public:
    bool isSafe(vector<int>&a , vector<int>&b)
    {
        if(a[0]==b[0] || a[1]==b[1])return true;
        return false;
    }
    void dfs(int j , vector<int>&vis , vector<vector<int>>&stones)
    {
        vis[j] =1;
        for(int i = 0 ; i < stones.size() ; i++)
        {
            if(!vis[i])
            {
                if(isSafe(stones[i] ,stones[j]))dfs(i,vis,stones);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,stones);
                count++;
            }
        }
        return n-count;
    }
};