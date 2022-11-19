class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(auto it : nums)
        {
            if(s.find(it)!=s.end())
            {
                return it;
            }
            s.insert(it);
        }
        return -1;
    }
};