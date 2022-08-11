class Solution {
public:
    int f(vector<int>& arr, int tar , int s , int e) {
        int mid = (s+e)/2;
        if(s>e)return -1;
        if(arr[mid]==tar)return mid;
        else if(arr[mid]>=arr[s])
        {
            if(tar >=arr[s] && arr[mid]>=tar)
            {
                return f(arr , tar , s, mid-1);
            }
            else{
                return f(arr , tar , mid+1,e);
            }
        }
        else
        {
            if(tar <=arr[e] && arr[mid]<=tar)
            {
                return f(arr , tar , mid+1, e);
            }
            else{
                return f(arr , tar , s , mid-1);
            }
        }
        return -1;
        
    }
    int search(vector<int>& nums, int target) {
        return f(nums,target,0,nums.size()-1);
    }
};