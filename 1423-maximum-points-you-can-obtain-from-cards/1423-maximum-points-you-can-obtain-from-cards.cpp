class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int sum = 0 ,maxi =INT_MIN;
        for(int i = 0 ; i < k ; i++)
        {
            sum+=arr[i];
        }
        maxi=max(maxi,sum);
        for(int i = k-1 ; i >=0 ; i--)
        {
            sum-=arr[i];
            sum+=arr[arr.size()-k+i];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};