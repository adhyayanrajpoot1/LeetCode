class Solution {
public:
    string frequencySort(string s) {
        string str;
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for(auto it : s)
        {
            mp[it]++;
        }
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        while(!pq.empty())
        {
            auto pairOfCI = pq.top();
            int freq = pairOfCI.first;
            while(freq--)str+=pairOfCI.second;
            pq.pop();
        }
        return str;
        
    }
};