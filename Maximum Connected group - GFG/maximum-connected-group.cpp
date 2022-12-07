//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
  public:
  vector<int>par , size;
  DisjointSet(int n)
  {
      par.resize(n+1,0);
      size.resize(n+1,1);
      for(int i = 0 ; i <= n ; i++)par[i] = i;
  }
  int find(int u)
  {
      if(par[u] == u)return u;
      return par[u] = find(par[u]);
  }
  void unionEle(int u , int v)
  {
      int x = find(u);
      int y = find(v);
      if(x==y)return;
      if(size[x]>size[y])
      {
          par[y] = x;
          size[x]+=size[y];
      }
      else{
          par[x] = y;
          size[y]+=size[x];
      }
  }
};
class Solution {
  public:
    bool isValid(int newR , int newC , int n , int m)
    {
        return (newR >=0 && newR < n && newC >= 0 && newC < m);
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*n);
        int dr[] = {-1,0,1,0,-1};
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j]==0)continue;
                for(int k = 0 ; k < 4 ; k++)
                {
                    int newR = dr[k] +i;
                    int newC = dr[k+1]+j;
                    if(isValid(newR,newC,n,m) && grid[newR][newC])
                    {
                        int nodeNo = i*m+j;
                        int adjNo = newR*m+newC;
                        ds.unionEle(nodeNo , adjNo);
                    }
                }
            }
        }
        int maxi = 0;
        for(int i =  0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j])continue;
                set<int>components;
                for(int k = 0 ; k < 4 ; k++)
                {
                    int newR = dr[k] +i;
                    int newC = dr[k+1]+j;
                    if(isValid(newR,newC,n,m) && grid[newR][newC])
                    {
                        //cout<<"nfjs ";
                        components.insert(ds.find(newR*m+newC));
                    }
                }
                int sizeTotal = 0 ;
                for(auto it : components)
                {
                    //cout<<ds.size[it];
                    sizeTotal+=ds.size[it];
                }
                maxi = max(maxi , sizeTotal+1);
            }
        }
        //for(int i = 0 ; i < n*n ; i++)cout << ds.size[ds.find(i)] << " ";
        for(int i = 0 ; i < n*n ; i++)
        {
            maxi = max(maxi , ds.size[ds.find(i)]);
        }
        return maxi;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends