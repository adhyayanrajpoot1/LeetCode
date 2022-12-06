//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    public:
    vector<int>par , rank;
    DisjointSet(int n)
    {
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0 ; i <= n ; i++)
        {
            par[i] = i;
        }
    }
    int findPar(int i)
    {
        if(par[i]==i)return i;
        return par[i] = findPar(par[i]);
    }
    
    void unionEle(int u , int v)
    {
        int a = findPar(u);
        int b = findPar(v);
        
        if(a==b)return;
        
        if(rank[a] > rank[b])
        {
            par[b] = a;
        }
        else if(rank[a] < rank[b])
        {
            par[a] = b;
        }
        else
        {
            par[a] = b;
            rank[b]++;
        }
    }
    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>edges;
        for(int i = 0 ; i < V ; i++)
        {
            for(auto it : adj[i])
            {
                int u = it[0];
                int wt = it[1];
                edges.push_back({wt,{u,i}});
            }
        }
        sort(edges.begin() , edges.end());
        DisjointSet ds(V);
        int ans = 0;
        for(auto it : edges)
        {
            int u = ds.findPar(it.second.first);
            int v = ds.findPar(it.second.second);
            int wt = it.first;
            if(u==v)continue;
            ans+=wt;
            ds.unionEle(u,v);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends