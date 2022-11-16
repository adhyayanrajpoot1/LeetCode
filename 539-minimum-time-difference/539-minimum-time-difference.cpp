class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>ans;
        for(auto it : timePoints)
        {
            string str = it;
            int hr = stoi(it.substr(0,2));
            int hm = stoi(it.substr(3,2));
            ans.push_back(hr*60+hm);
        }
        sort(ans.begin(),ans.end());
        ans.push_back(24*60+ans[0]);
        
        int diff = INT_MAX;
        for(int i = 0 ; i < ans.size()-1 ; i++)
        {
            diff = min(diff,(ans[i+1]-ans[i]));
        }
        return diff;
    }
};