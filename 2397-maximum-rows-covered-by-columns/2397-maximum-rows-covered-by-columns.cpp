class Solution {
public:
 int maximumRows(vector<vector<int>>& mat, int cols) {
        
        int currentCols = 0;
        vector<bool>visited(mat[0].size(),false);
        int ans = 0;
        pickColumns(mat, cols, 0, currentCols, visited, ans);
        return ans;
    }
    
    void pickColumns(vector<vector<int>>& mat, int cols, int index, int currentCols,
                    vector<bool>&visited, int&ans)
    {   
        if(index == mat[0].size())
        {   
            int count = 0;
            for(int i=0;i<mat.size();i++)
            {   bool flag = true;
                for(int j=0;j<mat[0].size();j++)
                {
                    if(mat[i][j]==1)
                    {  
                        if(visited[j]==false)
                        {flag = false;
                         break;
                        }
                    }
                }
                if(flag)
                {
                    count++;
                }
            }
            
            ans = max(ans,count);
            return;
        }
        //pick this column
        if(currentCols<cols)
        { visited[index] = true;
          pickColumns(mat,cols, index+1, currentCols+1,visited,ans);
          visited[index] = false;
        }
        //not pick the column
        pickColumns(mat,cols,index+1,currentCols,visited,ans);
    }
};