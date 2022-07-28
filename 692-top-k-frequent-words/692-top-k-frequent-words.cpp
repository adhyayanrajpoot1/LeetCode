class cmp{
    public : 
    bool operator()(const pair<int ,string >p1 ,const pair<int, string>p2)
    {
        if(p1.first < p2.first){
            return true;
        }
        else if(p1.first==p2.first)
        {
            return p1.second>p2.second;
        }
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(auto it : words)
        {
            m[it]++;
        }
        priority_queue< pair<int,string> , vector<pair<int,string>> , cmp >q;
        for(auto it : m)
        {
            q.push({it.second , it.first});
        }
        vector<string>ans;
        for(int i = 0 ; i < k ; i++)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
        
    }
};