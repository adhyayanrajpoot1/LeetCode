class Solution {
public:
    int dfs(int row , int col , vector<vector<int>>&grid)
    {
        if(row==grid.size())return col;
        int newCol = col +grid[row][col];
        if(newCol<0 || newCol >grid[0].size()-1 || grid[row][col]!=grid[row][newCol])return -1;
        return dfs(row+1,newCol,grid);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans(grid[0].size());
        for(int i = 0 ; i < grid[0].size() ; i++)
        {
            ans[i] = dfs(0,i , grid);
        }
        return ans;
    }
};