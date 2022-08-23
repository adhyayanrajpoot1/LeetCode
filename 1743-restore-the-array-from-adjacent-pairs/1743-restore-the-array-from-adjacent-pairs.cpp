class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&m , set<int>&s , vector<int>&ans,int a)
    {
        if(s.find(a)!=s.end())return;
        s.insert(a);
        ans.push_back(a);
        for(auto it : m[a])
        {
            dfs(m,s,ans,it);
        }
       
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>m;
        
        for(int i = 0 ; i < adjacentPairs.size() ; i++)
        {
            m[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        int start;
        for(auto it : m)
        {
            if(it.second.size()==1){
                start=it.first;
                break;
            }
        }
        vector<int>ans;
        //ans.push_back(start);
        set<int>s;
        //s.insert(start);
        dfs(m,s,ans,start);
        return ans;
    }
};