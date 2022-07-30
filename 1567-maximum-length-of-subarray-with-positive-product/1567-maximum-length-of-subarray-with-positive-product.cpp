class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n ;)
        {
            int s = i;
            while(s<n and nums[s]==0)s++;
            int e = s;
            int sn = -1, en = -1;
            int countN =0 ;
            while(e<n and nums[e]!=0)
            {
                if(nums[e]<0){
                    countN++;
                    if(sn==-1)sn=e;
                    en = e;
                }
                e++;
            }
            if(countN%2==0)ans = max(ans,e-s);
            else{
                if(sn!=-1)ans=max(ans,e-sn-1);
                if(en!=-1)ans=max(ans,en-s);
            }
            i=e+1;
        }
        return ans;
        
        
    }
};

// class Solution {
// public:
//     int getMaxLen(vector<int>& nums) {
//         int n = nums.size();
//         int countN = 0;
//         int countP = 0,temp;
//         int maxi = INT_MIN;
//         for(int i = 0 ; i < n ; i++){
//             if(nums[i]==0)
//             {
//                 countN = 0;
//                 countP = 0;
                    
//             }
//             else if(nums[i] > 0){
//                 countP++;
//                 if(countN>0)
//                     countN++;
//             }
//             else{
//                 if(countN>0)
//                     temp = countN + 1;
//                 else
//                     temp = 0;
//                 countN = countP+1;
//                 countP = temp;
//             }
//             maxi = max(maxi, countP);
//         }
        
//         return maxi;
//     }
// };