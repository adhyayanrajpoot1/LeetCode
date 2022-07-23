class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int arrL[n];
        int arrR[n];
        if(n==0 || n==1)return 0;
        arrL[0]=height[0];
        for(int i = 1; i < n ; i++)
        {
            arrL[i]=max(arrL[i-1],height[i]);
        }
        arrR[n-1]=height[n-1];
        for(int i = n-2 ; i>=0 ; i--)
        {
            arrR[i] = max(arrR[i+1],height[i]);
        }
        int area[n];
        int sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            area[i] = min(arrL[i],arrR[i])-height[i];
            sum+=area[i];
        }
        return sum;
    }
};