//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
  public:
  vector<int>rank , par;
  DisjointSet(int n)
  {
      rank.resize(n+1,0);
      par.resize(n+1);
      for(int i = 0 ; i <= n ; i++)
      {
          par[i] = i;
      }
  }
  int find(int u){
      if(par[u] == u)return u;
      return par[u] = find(par[u]);
  }
  void unionEle(int u , int v)
  {
      int x = find(u);
      int y = find(v);
      if(x==y)return;
      
      if(rank[x] > rank[y])
      {
          par[y] = x;
      }
      else if(rank[x] < rank[y])
      {
          par[x] = y;
      }
      else
      {
          par[x] = y;
          rank[y]++;
      }
  }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int vis[n][m];
        memset(vis , 0 , sizeof vis);
        DisjointSet ds(n*m);
        
        int dr[] = {-1,0,1,0,-1};
        vector<int>ans;
        int count= 0;
        for(auto it : operators)
        {
            int x = it[0];
            int y = it[1];
            if(vis[x][y]==1){
                ans.push_back(count);
                continue;
            }
            count++;
            vis[x][y] = 1;
            
            for(int i = 0 ; i < 4 ; i++)
            {
                int newR = dr[i] + x;
                int newC = dr[i+1]+y;
                
                if(newR < n && newR >= 0 && newC < m && newC >=0)
                {
                    if(vis[newR][newC]==1)
                    {
                        int cellNo = x * m + y;
                        int adjCellNo = newR*m + newC;
                        int parOri = ds.find(cellNo);
                        int parAdj = ds.find(adjCellNo);
                        if(parOri != parAdj){
                            count--;
                            ds.unionEle(parOri , parAdj);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends