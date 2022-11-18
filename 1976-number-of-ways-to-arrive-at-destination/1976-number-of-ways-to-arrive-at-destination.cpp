class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        vector<long long>dist(n,LONG_MAX);
        vector<long long>ways(n,0);
        priority_queue<pair<long long,long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0] =1;
        
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            long long ele = node.second;
            long long dis = node.first;
            if(dis>dist[ele])continue;
            
            for(auto it : adj[ele])
            {
                long long toDist = it.second;
                long long toEle = it.first;
              
                if(dist[toEle] > toDist+dis)
                {
                    dist[toEle] = (toDist+dis);
                    ways[toEle] = ways[ele];
                    pq.push({dist[toEle] , toEle});
                }
                else if(dist[toEle] == toDist+dis)
                {
                    //dist[toEle] = toDist+dis;
                    ways[toEle] =  (ways[toEle]+ways[ele])%mod;
                    //pq.push({dist[toEle] , toEle});
                }
                
            }
            
            
        }
        cout<<dist[n-1];
        return ways[n-1];
    }
};
