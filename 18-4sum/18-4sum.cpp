class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            
            for(int j = i+1 ; j < nums.size() ; j++)
            {
                long target2 =(long)target-(nums[i]+nums[j]);
                int front = j+1;
                int back = nums.size()-1;
                
                while(front<back)
                {
                    long temp = nums[front]+nums[back];
                    if(temp<target2)front++;
                    else if(temp>target2)back--;
                    else
                    {
                        vector<int>smallAns;
                        smallAns.push_back(nums[i]);
                        smallAns.push_back(nums[j]);
                        smallAns.push_back(nums[front]);
                        smallAns.push_back(nums[back]);
                        ans.push_back(smallAns);
                        while(front<back && nums[front]==smallAns[2])front++;
                        while(front<back && nums[back]==smallAns[3])back--;
                    }
                    
                    
                }
                while(j+1<nums.size() &&nums[j+1]==nums[j])j++;
                
            }
                while(i+1<nums.size() &&nums[i+1]==nums[i])i++;
            
        }
        return ans;
    }
};