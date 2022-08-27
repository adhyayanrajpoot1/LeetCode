class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        vector<vector<int>>ans(mat.size() , vector<int>(mat[0].size(),-1));
        
        for(int i = 0 ; i < mat.size() ; i++)
        {
            for(int j = 0 ; j < mat[0].size() ; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int n = mat.size();
        int m = mat[0].size();
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            if(check(i+1,j,m,n) && ans[i+1][j]==-1)
            {
                q.push({i+1,j});
                ans[i+1][j] = ans[i][j]+1;
            }
            if(check(i,j-1,m,n) && ans[i][j-1]==-1)
            {
                q.push({i,j-1});
                ans[i][j-1] = ans[i][j]+1;
            }
            if(check(i,j+1,m,n) && ans[i][j+1]==-1)
            {
                q.push({i,j+1});
                ans[i][j+1] = ans[i][j]+1;
            }
            if(check(i-1,j,m,n) && ans[i-1][j]==-1)
            {
                q.push({i-1,j});
                ans[i-1][j] = ans[i][j]+1;
            }
            q.pop();
            
        }
        return ans;
    }
    bool check(int i,int j,int m , int n)
    {
        if(i>=0 && i<n && j>=0 && j<m)return true;
        return false;
    }
};