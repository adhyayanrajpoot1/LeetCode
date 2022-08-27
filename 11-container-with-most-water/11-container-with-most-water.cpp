class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size()-1;
        int maxi = INT_MIN;
        while(i<=j)
        {
            int sum = min(height[i],height[j]);
            sum *=abs(i-j);
            maxi = max(maxi,sum);
            if(height[i]<height[j])i++;
            else j--;
        }
        return maxi;
    }
};