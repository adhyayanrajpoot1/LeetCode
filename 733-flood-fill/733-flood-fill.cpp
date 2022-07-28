class Solution {
public:
    int original;
    void flood_fill(int r , int c , vector<vector<int>>& image,int color)
    {
        int n = image.size();
        int m = image[0].size();
        image[r][c] = color;
        int d[] = {0,1,0,-1,0};
        
        for(int k = 0;  k < 4 ; k++)
        {
            int dx = r+d[k];
            int dy = c+d[k+1];
            if(dx>=0 && dy>=0 && dx<n && dy<m && image[dx][dy]==original)
            {
                flood_fill(dx,dy,image,color);
            }
        }
        
    }
    vector<vector<int>>vis;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vis.resize(n,vector<int>(m,0));
        this->original = image[sr][sc];
        if(original==color)return image;
        flood_fill(sr,sc,image,color);
        return image;
    }
};