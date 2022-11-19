class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = nums1.size()-1;
        while(i>=0 && j>=0 && k>=0)
        {
            if(nums1[i]<nums2[j])
            {
                nums1[k--] = nums2[j];
                //cout<<nums2[j]<<" ";
                j--;
            }
            else{
                nums1[k--] = nums1[i];
                //cout<<nums1[i] <<" ";
                i--;
            }
        }
        while(j>=0 && k>=0)
        {
            nums1[k--] = nums2[j--];
        }
        while(i>=0 && k>=0)
        {
            nums1[k--] = nums1[i--];
        }
    }
};