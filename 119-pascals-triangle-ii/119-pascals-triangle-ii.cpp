class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        long long value = 1;
        for(int i = 0 ; i < rowIndex ; i++)
        {
            ans.push_back(value);
            value = value*(rowIndex-i)/(i+1);
            
        }
        ans.push_back(value);
        return ans;
    }
};