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
            //if(dis>dist[ele])
            
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
//     int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
//         vector<ll> dist(n, LONG_MAX);
//         vector<ll> ways(n);
//         ways[src] = 1;
//         dist[src] = 0;
//         priority_queue<pll, vector<pll>, greater<>> minHeap;
//         minHeap.push({0, 0}); // dist, src
//         while (!minHeap.empty()) {
//             auto[d, u] = minHeap.top(); minHeap.pop();
//             if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
//             for(auto [v, time] : graph[u]) {
//                 if (dist[v] > d + time) {
//                     dist[v] = d + time;
//                     ways[v] = ways[u];
//                     minHeap.push({dist[v], v});
//                 } else if (dist[v] == d + time) {
//                     ways[v] = (ways[v] + ways[u]) % MOD;
//                 }
//             }
//         }
//         return ways[n-1];
//     }
// };
