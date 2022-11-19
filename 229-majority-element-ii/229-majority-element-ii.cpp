class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1;
        int ele2 = -1;
        int c1 =0 ,  c2 = 0;
        
        for(auto it: nums)
        {
            if(it==ele1)
            {
                c1++;
            }
            else if(it==ele2)c2++;
            else if(c1==0)
            {
                ele1 = it;
                c1++;
            }
            else if(c2==0)
            {
                ele2 = it;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        // if(c1>c2)return ele1;
        // else if(c2>c1)return ele2;
        // else
        // 
            int t1 = 0 , t2 = 0;
            for(auto it : nums)
            {
                if(it==ele1)t1++;
                else if(it==ele2)t2++;
            }
        vector<int>ans;
            if(t1>nums.size()/3)ans.push_back(ele1);
            if(t2>nums.size()/3)ans.push_back(ele2);
        return ans;
        
        //}
        
    }
};