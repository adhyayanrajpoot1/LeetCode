class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            int s1= nums[i][0];
            int e1 = nums[i][1];
            int count=0;
            for(int j = i; j < n ; j++)
            {
                  //fully oveerlap
                if(i==j)continue;
                if(nums[j][1]<=e1 && nums[j][0]>=s1)
                {
                    e1=e1;
                    count++;
                }
                //partial overlap
                else if(nums[j][0]<=e1){
                    e1= nums[j][1];
                    count++;
                }
//                 else{
                    
//                     break;
//                 }    
                //no overlap
            }
            
            cout<<i<<" " <<count<<" "<<endl;
            i+=count;
            ans.push_back({s1,e1});
        }
        return ans;
        
    }
};