class Solution {
public:
    void dfs(int i , int j , int color , int target , vector<vector<int>>&image)
    {
        int n = image.size();
        int m = image[0].size();
        if(i<0 || j<0 || i==n || j==m || image[i][j]==color)return;
        if(image[i][j]==target)
        {
            image[i][j] = color;
            
            dfs(i+1,j,color,target,image);
            dfs(i,j+1,color,target,image);
            dfs(i-1,j,color,target,image);
            dfs(i,j-1,color,target,image);
            //image[i][j] = target
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        
        dfs(sr,sc,color,target,image);
        return image;
        
    }
};