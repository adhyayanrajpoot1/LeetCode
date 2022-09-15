class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>m;
        vector<int>ans;
        int n = changed.size();
        if(n%2)return {};
        for(auto it : changed)m[it]++;
        sort(changed.begin(),changed.end());
        for(auto it : changed)
        {
            if(m[it]==0)continue;
            if(m[it*2]==0)return {};
            ans.push_back(it);
            m[it]--;
            m[it*2]--;
        }
        return ans;
        
    }
};