//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    public:
    vector<int>size , par;
    DisjointSet(int n){
        size.resize(n+1,0);
        par.resize(n+1);
        for(int i = 0 ; i <= n ; i++)
        {
            par[i] = i;
        }
    }
    int findPar(int u)
    {
        if(par[u]==u)return u;
        return par[u] = findPar(par[u]);
    }
    void unionBySize(int u , int v)
    {
        int x = findPar(u);
        int y = findPar(v);
        
        if(x==y)return;
        
        if(size[x] > size[y])
        {
            par[y] = x;
            size[x] += size[y];
        }
        else
        {
            par[x] = y;
            size[y] += size[x];
        }
    }
};


class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        unordered_map<string,  int>m;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i = 0 ; i < n ; i++)
        {
            int j = 0;
            for(auto it : accounts[i])
            {
                if(j==0){j++ ; continue;}
                if(m.find(it)==m.end()){
                    m[it] = i;
                }
                else
                {
                    ds.unionBySize(m[it] , i);
                }
            }
        }
        vector<string>mergedMails[n];
        for(auto it : m)
        {
            string str = it.first;
            int num = it.second;
            int fp = ds.findPar(num);
            mergedMails[fp].push_back(str);
        }
        
        vector<vector<string>>ans;
        for(int i = 0 ; i < n ; i++)
        {
            if(mergedMails[i].size()==0)continue;
            sort(mergedMails[i].begin() , mergedMails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMails[i])temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends