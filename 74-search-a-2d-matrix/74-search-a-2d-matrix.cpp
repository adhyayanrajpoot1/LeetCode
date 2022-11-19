class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            int a = matrix[i][0] ;
            int b = matrix[i][m-1];
            if(target>=a && target<=b)
            {
                for(int j = 0 ; j < m ; j++)
                {
                    if(target==matrix[i][j])return true;
                }
            }
        }
        return false;
    }
};