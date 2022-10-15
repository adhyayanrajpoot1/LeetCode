class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>G(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it : prerequisites)
        {
            G[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<int>bfs;
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(indegree[i]==0)bfs.push_back(i);
        }
        for(int i = 0 ; i < bfs.size() ; i++)
        {
            for(int j : G[bfs[i]])
            {
                if(--indegree[j]==0)bfs.push_back(j);
            }
        }
        return bfs.size()==numCourses;
    }
};
    
    