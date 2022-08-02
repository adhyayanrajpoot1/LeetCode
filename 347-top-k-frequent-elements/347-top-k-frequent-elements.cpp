class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ans;
        for(auto it : nums){
            ans[it]++;
        }
        priority_queue<pair<int,int>>p;
        for(auto it : ans)
        {
            p.push({it.second , it.first});
        }
        vector<int>a;
        while(k--){
            a.push_back(p.top().second);
            p.pop();
        }
        return a;
    }
};