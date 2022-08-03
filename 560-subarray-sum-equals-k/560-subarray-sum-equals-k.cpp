class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>mapp;
        
        int sum=0;
        int n= arr.size();
        int ans=0;
        
        for(int i = 0; i < n ; i++)
        {   sum+=arr[i];
            if(sum==k)ans++;
            if(mapp.find(sum-k)!=mapp.end())
                ans=mapp[sum-k]+ans;
            
            mapp[sum]++;
            
            
        }
        return ans;
    }
};