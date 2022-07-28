class Solution {
public:
    
    void f(int i , int j,vector<vector<char>>& grid)
    {
        grid[i][j] = '2';
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
                f(xx,yy,grid);
                
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                //cout<<grid[i][j]<<endl;
                if(grid[i][j]=='1'){
                    count++;
                    f(i,j,grid);
                    //cout<<grid[i][j]<<endl;
                }
            }
        }
        return count;
        
        
    }
};