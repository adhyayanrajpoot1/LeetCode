class Solution {
public:
    void floodfill(vector<vector<int>>& grid , int i, int j , vector<pair<int,int>>&p)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j]==0)
            return;
        grid[i][j]=0;
        p.push_back({i,j});
        int dk[] = {0,-1,0,1,0};
        for(int k = 0 ; k < 4 ; k++)
        {
            int aa = i+dk[k];
            int bb = j+dk[k+1];
            floodfill(grid,aa,bb,p);
            //return;
        }
    }
     void dfs(vector<vector<int>>& A, int i, int j, vector <pair<int, int>> &r)
    {
        
        A[i][j] = 0;
        r.push_back(make_pair(i,j));
        dfs(A, i+1, j, r);
        dfs(A, i-1, j, r);
        dfs(A, i, j-1, r);
        dfs(A, i, j+1, r);
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
        
        int count=0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0; j < grid[0].size() ; j++)
            {
                if(grid[i][j]==1){
                    count++;
                    if(count==1){
                        floodfill(grid , i , j , x);
                    }
                    else if(count==2){
                        floodfill(grid , i , j , y);
                    }
                }
            }
        }
        int mini = INT_MAX;
        for(int i = 0 ; i < x.size() ; i++)
        {
            for(int j = 0 ; j < y.size() ; j++)
            {
                int dist = abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second)-1;
                if(dist<mini)mini = dist;
            }
        }
        return mini;
    }
};