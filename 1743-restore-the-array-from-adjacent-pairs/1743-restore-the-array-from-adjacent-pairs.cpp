class Solution {
public:
    struct Vec {
        int _size = 0;
        int v[2];
        void push_back(int x) {
            v[_size++] = x;
        }
        int size() {
            return _size;
        }
        int operator[](int i) {
            return v[i];
        }
    };
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,Vec> neighbours;
        for(auto &pr : adjacentPairs) {
            neighbours[pr[0]].push_back(pr[1]);
            neighbours[pr[1]].push_back(pr[0]);
        }
        
        int n = adjacentPairs.size()+1;
        vector<int> result;
        result.reserve(n);
        for(auto &pr : neighbours) {
            if(pr.second.size() == 1) {
                result.push_back(pr.first);
                break;
            }
        }
        
        for(int i = 1; i < n; ++i) {
            auto &v = neighbours[result.back()];
            if(v.size() == 1)
                result.push_back(v[0]);
            else if(result.size() >= 2 && v[0] == result[result.size()-2])
                result.push_back(v[1]);
            else
                result.push_back(v[0]);
        }

        return result;
    }
};

// class Solution {
// public:
    
//     void dfs(int ele,set<int>&v ,vector<int>&ans , unordered_map<int,vector<int>>&mapp)
//     {
//         // if(v.find(ele)!=v.end())return;
//         ans.push_back(ele);
//         v.insert(ele);
//         for(auto it : mapp[ele])
//         {
//             if(v.find(it)==v.end())
//                 dfs(it,v,ans,mapp);
//         }
//     }
//     vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
//         int n = adjacentPairs.size();
//         unordered_map<int,vector<int>>mapp;
//         set<int>v;
//         vector<int>ans;
//         for(auto &it: adjacentPairs)
//         {
//             mapp[it[0]].push_back(it[1]);
//             mapp[it[1]].push_back(it[0]);
//         }
//         int head;
        
//         for(auto it : mapp)
//         {
//             if(it.second.size()==1){
//                 head=it.first;
//                 break;
//             }
//         }
//         dfs(head,v,ans,mapp);
//         return ans;
        
//     }
// };