class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n+1];
        for(auto it : edges)
        {
            int i = it[0];
            int j = it[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        vector<int>mini(n+1,-1) ; vector<int>smini(n+1,-1);
        queue<pair<int,int>>q;
        q.push({1,1});
        mini[1] = 0;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int ele = node.first;
            //freq[ele]++;
            //if(fre[ele]==2)
            int freq = node.second;
            int signal = freq==1 ? mini[ele] : smini[ele];
            if((signal/change)%2)
            {
                signal = change*(signal/change+1)+time;
            }
            else
            {
                signal = signal+time;
            }
            for(auto it : adj[ele])
            {
                if(mini[it]==-1)
                {
                    mini[it] = signal;
                    q.push({it,1});
                }
                else
                {
                    if(smini[it]==-1 && mini[it]!=signal)
                    {
                        q.push({it,2});
                        smini[it] = signal;
                        if(it==n)return signal;
                    }
                }
            }
            
            
        }
        return 0;
    }
};