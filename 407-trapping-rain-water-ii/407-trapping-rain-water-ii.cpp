class Solution {
public:
    
int trapRainWater(vector<vector<int>> &height)
{

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> mn;
    int n = height.size();
    int m = height[0].size();
    //bool vis[m][n];
    //memset(vis, false, sizeof(vis));
       vector<vector<int>>vis(n,vector<int>(m,0));
            for(int i = 0 ; i < n ; i++)
        {
            vis[i][0] = vis[i][m-1] = 1;
            mn.push({height[i][0] , {i,0}});
            mn.push({height[i][m-1] , {i,m-1}});
        }
        for(int i = 0 ; i < m ; i++)
        {
            vis[0][i] = vis[n-1][i] = 1;
            mn.push({height[0][i] , {0,i}});
            mn.push({height[n-1][i] , {n-1,i}});
        }
    int dr[] = {-1,0,1,0,-1};
    int water = 0;

    while (mn.size() > 0)
    {
        pair<int, pair<int, int>> p = mn.top();
        mn.pop();
        for (int i = 0; i < 4; i++)
        {
            int rowdash = p.second.first + dr[i];
            int coldash = p.second.second + dr[i+1];

            if (rowdash >= 0 && rowdash < n && coldash >= 0 && coldash < m && vis[rowdash][coldash] == false)
            {
                water += max(0, p.first - height[rowdash][coldash]);

                if (p.first > height[rowdash][coldash])
                    mn.push({p.first,{rowdash,coldash}});
                else
                    mn.push({height[rowdash][coldash],{rowdash, coldash}});
                vis[rowdash][coldash] = true;
            }
            
        }
    }
    return water;
}
};
// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int n = heightMap.size();
//         int m = heightMap[0].size();
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
//         for(int i = 0 ; i < n ; i++)
//         {
//             vis[i][0] = vis[i][m-1] = 1;
//             pq.push({heightMap[i][0] , {i,0}});
//             pq.push({heightMap[i][m-1] , {i,m-1}});
//         }
//         for(int i = 0 ; i < m ; i++)
//         {
//             vis[0][i] = vis[n-1][i] = 1;
//             pq.push({heightMap[0][i] , {0,i}});
//             pq.push({heightMap[n-1][i] , {n-1,i}});
//         }
//         int dr[] = {-1,0,1,0,-1};
//         int ans= 0;
//         while(!pq.empty())
//         {
//             auto node = pq.top();
//             pq.pop();
//             int h = node.first;
//             int i = node.second.first;
//             int j = node.second.second;
            
//             for(int i = 0 ;i < 4 ; i++)
//             {
//                 int x = i+dr[i];
//                 int y = j+dr[i+1];
//                 if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0)
//                 {
//                     ans+=max(0,h-heightMap[x][y]);
//                     pq.push({max(h,heightMap[x][y]) , {x,y}});
//                     vis[x][y]=1;
                    
//                 }
//             }
            
//         }
//         return ans;
        
        
//     }
// };