class Solution {
public:
    void print(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++)
            {
                cout << grid[i][j]<<" ";
            }
            cout << endl;
        }
    }
    int count_col[50000]={0};
    
    void flood_fill(int i,int j,vector<vector<int>>& grid,int col)
    {
        grid[i][j]=col;
        count_col[col]++;
        //visited
        int d[] = {0,1,0,-1,0};
        int n = grid.size();
        int m = grid[0].size();
        for(int k = 0 ; k < 4 ; k++)
        {
            int dx = i+d[k];
            int dy = j+d[k+1];
            if(dx>=0 && dy>=0 && dx<n && dy <m && grid[dx][dy]==1)
            {
                flood_fill(dx,dy,grid,col);
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalCount=1;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j]==1)
                {
                    totalCount++;
                    flood_fill(i,j,grid,totalCount);
                }
            }
        }
        int largestIsland = 0;
        for(int i = 2 ; i <=totalCount ; i++)
        {
            largestIsland = max(largestIsland,count_col[i]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j]==0)
                {
                    set<int>s;
                    int d[] = {0,1,0,-1,0};
                    for(int k = 0 ; k < 4 ; k++)
                    {
                        int dx = i+d[k];
                        int dy = j+d[k+1];
                        if(dx>=0 && dy>=0 && dx<n && dy <m)
                        {
                            s.insert(grid[dx][dy]);
                        }
                    }
                    int ans=1;
                    for(auto st : s)
                    {
                        ans+=count_col[st];
                    }
                    largestIsland = max(largestIsland,ans);
                }
            }
        }
        //print(grid);
        return largestIsland;
    }
};