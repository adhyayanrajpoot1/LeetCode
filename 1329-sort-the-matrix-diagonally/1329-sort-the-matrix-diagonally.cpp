class Solution {
public:
    void f(vector<vector<int>>& mat , int r , int c)
    {
        int n = mat.size();
        int m = mat[0].size();
        int*arr = new int[101]();
        int i = r;
        int j = c;
        while(i<n && j <m)
        {
            arr[mat[i][j]]++;
            i++;
            j++;
        }
        i = r , j = c;
        for(int k = 1 ; k < 101 ; k++)
        {
            //cout<<arr[k]<<" ";
            while(arr[k]>0)
            {
                
                mat[i][j] = k;
                arr[k]--;
                i++;
                j++;
            }
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0 ; i < m ; i++)
        {
            f(mat,0,i);
        }
        for(int j = 1 ; j < n ; j++)
        {
            f(mat,j,0);
        }
        return mat;
    }
};