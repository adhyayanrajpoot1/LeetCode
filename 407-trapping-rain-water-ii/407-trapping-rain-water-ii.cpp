class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        for(int i = 0 ; i < n ; i++)
        {
            vis[i][0] = vis[i][m-1] = 1;
            pq.push({heightMap[i][0] , {i,0}});
            pq.push({heightMap[i][m-1] , {i,m-1}});
        }
        for(int i = 0 ; i < m ; i++)
        {
            vis[0][i] = vis[n-1][i] = 1;
            pq.push({heightMap[0][i] , {0,i}});
            pq.push({heightMap[n-1][i] , {n-1,i}});
        }
        int dr[] = {-1,0,1,0,-1};
        int ans= 0;
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            int h = node.first;
            int i = node.second.first;
            int j = node.second.second;
            
            for(int k = 0 ;k < 4 ; k++)
            {
                int x = i+dr[k];
                int y = j+dr[k+1];
                if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0)
                {
                    ans+=max(0,h-heightMap[x][y]);
                    pq.push({max(h,heightMap[x][y]) , {x,y}});
                    vis[x][y]=1;
                    
                }
            }
            
        }
        return ans;
        
        
    }
};