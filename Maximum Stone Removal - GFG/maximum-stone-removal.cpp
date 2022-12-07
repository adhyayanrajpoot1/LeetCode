//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow = 0 , maxCol = 0;
        for(auto it : stones)
        {
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol , it[1]);
        }
        unordered_map<int,int>m;
        DisjointSet ds(maxRow+maxCol+1);
        
        for(auto it : stones)
        {
            int row = it[0];
            int col = it[1]+maxRow+1;
            ds.unionEle(row,col);
            m[row] = 1;
            m[col] = 1;
        }
        int count =0 ;
        for(auto it : m)
        {
            if(ds.find(it.first) == it.first)count++;
        }
        return n-count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends