//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer=0;
    void dfs(int node , int parent , vector<int>&tim , vector<int>&low , vector<int>&vis ,vector<int>&mark,vector<int>adj[])
    {
        vis[node]=1;
        tim[node] = low[node] = timer++;
        int child = 0;
        for(auto it : adj[node])
        {
            if(it==parent)continue;
            if(!vis[it])
            {
                dfs(it,node,tim,low,vis,mark,adj);
                low[node] = min(low[node] , low[it]);
                if(tim[node]<=low[it] && parent!=-1)mark[node]=1;
                child++;
            }
            else
            {
                low[node] = min(low[node] , tim[it]);
            }
        }
        if(child>1 && parent==-1)mark[node]=1;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>vis(V,0) , mark(V,0);
        vector<int>tim(V,0) , low(V,0);
        dfs(0,-1,tim , low , vis , mark ,adj);
        vector<int>ans;
        for(int i = 0 ; i < mark.size() ; i++)
        {
            if(mark[i])ans.push_back(i);
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends