class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int n = numRows;
        for(int i = 0; i < n ; i++)
        {
            vector<int>small(i+1);
            small[0]=1;small[i]=1;
            for(int j = 1 ; j < i ; j++)
            {
                small[j]= ans[i-1][j]+ans[i-1][j-1];
            }
            ans.push_back(small);
        }
        return ans;
    }
};