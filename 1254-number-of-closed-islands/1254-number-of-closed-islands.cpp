class Solution {
public:
    void print(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                cout << grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void flood_fill(int i,int j,vector<vector<int>>& grid)
    {
        grid[i][j] = 1;
        int d[] = {0,1,0,-1,0};
        int n = grid.size();
        int m = grid[0].size();
        
        for(int k = 0 ; k < 4 ; k++)
        {
            int xx = i+d[k],yy = j+d[k+1];
            if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]==0)
            {
                flood_fill(xx,yy,grid);
                
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(i*j==0 ||i==n-1 || j==m-1)
                {
                    if(grid[i][j]==0)
                    {
                        flood_fill(i , j , grid);
                    }
                }
            }
        }
        //print(grid);
        int count=0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    flood_fill(i,j,grid);
                }
            }
        }
        //print(grid);
        return count;
    }
};