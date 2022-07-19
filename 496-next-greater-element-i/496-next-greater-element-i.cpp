class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans(nums1.size(),0);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(nums2[j]==nums1[i])
                {
                    j++;
                    while(j<m && nums2[j]<nums1[i])
                    {
                        j++;
                    }
                    if(j>=m)ans[i]=-1;
                    else ans[i]=(nums2[j]);
                }
            }
        }
        return ans;
        
    }
};