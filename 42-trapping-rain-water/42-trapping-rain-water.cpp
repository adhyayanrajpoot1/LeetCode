class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0;
        int rmax = 0;
        int l = 0;
        int r = height.size()-1;
        int n = height.size();
        int ans = 0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]<lmax)
                { 
                    ans+=(lmax-height[l]);
                    
                }
                else
                {
                    lmax = height[l];
                }
                l++;
            }
            else
            {
                if(height[r]>rmax)
                {
                    rmax = height[r];
                }
                else
                {
                    ans+=(rmax-height[r]);
                }
                r--;
            }
        }
        return ans;
        
    }
};