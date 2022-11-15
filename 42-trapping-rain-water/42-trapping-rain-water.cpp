class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>lmax(n,0) , rmax(n,0);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];
        for(int i = 1 ; i < n ; i++)
        {
            lmax[i] = max(height[i] ,lmax[i-1]);
        }
        for(int i = n-2 ; i>=0 ; i--)
        {
            rmax[i] = max(height[i] , rmax[i+1]);
            
        }
        //for(auto it : rmax)cout<<it <<" ";
        //cout<<endl;
        int ans =0 ;
        for(int i = 0 ; i < n ; i++)
        {
            int h = min(lmax[i],rmax[i]);
            ans += abs(h-height[i]);
            //cout <<ans <<" ";
        }
        return ans;
    }
};