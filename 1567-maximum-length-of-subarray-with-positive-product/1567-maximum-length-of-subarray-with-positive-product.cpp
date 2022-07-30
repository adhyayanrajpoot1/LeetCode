class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int countN = 0;
        int countP = 0,temp;
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==0)
            {
                countN = 0;
                countP = 0;
                    
            }
            else if(nums[i] > 0){
                countP++;
                if(countN>0)
                    countN++;
            }
            else{
                if(countN>0)
                    temp = countN + 1;
                else
                    temp = 0;
                countN = countP+1;
                countP = temp;
            }
            maxi = max(maxi, countP);
        }
        
        return maxi;
    }
};