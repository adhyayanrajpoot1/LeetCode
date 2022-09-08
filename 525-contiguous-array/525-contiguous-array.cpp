class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        //m.insert(0,-1);
        m[0]=-1;
        int maxLen = 0 , count =0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            count  = count+(nums[i]==1 ? 1 : -1);
            if(m.find(count)!=m.end())
            {
                maxLen = max(maxLen , i - m[count]);
            }
            else
            {
                //m.insert(count,i);
                m[count] = i;
            }
        }
        return maxLen;
    }
};