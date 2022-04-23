class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            if(hashtable.find(target-nums[i])!=hashtable.end()){
                v.push_back(i);
                v.push_back(hashtable[target-nums[i]]);
            }
            else{
                hashtable[nums[i]]=i;
            }
        }
        return v;
    }
};