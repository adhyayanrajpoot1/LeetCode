// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         bool ans=false;
//         for(int i = 0 ; i < n ; i++)
//         {
//             if(matrix[i][0]<=target)
//             {
//                 auto it = lower_bound(matrix[i].begin(),matrix[i].end(),target);
//                 cout<<*it<<" ";
                
//                 // if(it!=matrix[i].end()){
//                     if(matrix[i][*it%m]==target)return true;
                
                
//             }
//             else break;
//         }
//         return false;
//     }
// };
class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int id = 0, m = matrix.size(), n = matrix[0].size(), pivot = 0;
        while (id < m) {
            if (target >= matrix[id][0] && target <= matrix[id][n - 1])   {
                auto it = lower_bound(matrix[id].begin(), matrix[id].end(), target);
                if (*it == target)  return true;
                //pivot = it - matrix[id].begin() - 1;
            }
            id++;
        }
        return false;
    }
};