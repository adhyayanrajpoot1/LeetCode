class Solution {
public:
    
    void dfs(int ele,set<int>&v ,vector<int>&ans , unordered_map<int,vector<int>>&mapp)
    {
        // if(v.find(ele)!=v.end())return;
        ans.push_back(ele);
        v.insert(ele);
        for(auto it : mapp[ele])
        {
            if(v.find(it)==v.end())
                dfs(it,v,ans,mapp);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int,vector<int>>mapp;
        set<int>v;
        vector<int>ans;
        for(auto &it: adjacentPairs)
        {
            mapp[it[0]].push_back(it[1]);
            mapp[it[1]].push_back(it[0]);
        }
        int head;
        
        for(auto it : mapp)
        {
            if(it.second.size()==1){
                head=it.first;
                break;
            }
        }
        dfs(head,v,ans,mapp);
        return ans;
        
    }
};