class Solution {
public:
    vector<vector<int>>visited;

void flood_fill(int i , int j ,vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    visited[i][j]=1;
    int dx[] = {0,1,0,-1,0};
    for(int k = 0 ; k < 4 ; k++)
    {
        int xx = i+dx[k];
        int yy = j+dx[k+1];
        if(xx>=0&&yy>=0 && xx<n && yy<m && visited[xx][yy]==0 && grid[xx][yy]=='1')
        {
            flood_fill(xx,yy,grid);
        }
    }
}
int numIslands( vector<vector<char>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    visited.resize(n , vector<int>(m,0));
    int count=0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ;j++)
        {
            if(grid[i][j]=='1' and visited[i][j]==0)
            {
                count++;
                flood_fill(i,j,grid);
            }
        }
    }
    return count;
}
};