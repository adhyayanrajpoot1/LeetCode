class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j ){
       
        
        grid[i][j] = '0';
        int d[] = {0,-1,0,1,0};
        int n = grid.size();
        int m = grid[0].size();
        for(int k = 0 ; k < 4 ; k++)
        {
            //cout<<grid[i][j]<<endl;
            int xx = d[k]+i;
            int yy = d[k+1]+j;
            if(xx<n && xx>=0 && yy>=0 && yy<m && grid[xx][yy]=='1')
            {
                //cout<<grid[i][j]<<endl;
                dfs(grid,xx,yy);
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};