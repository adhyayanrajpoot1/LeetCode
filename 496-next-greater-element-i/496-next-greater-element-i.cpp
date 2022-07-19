class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int>s;
        vector<int>ans;
        unordered_map<int,int>mapp;
        
        for(int j = m-1 ; j>=0 ; j--)
        {
            if(j==m-1){
                ans.push_back(-1);
                //s.push(nums2[j]);
            }
            else if(!s.empty() && nums2[j]<s.top())
            {
                ans.push_back(s.top());
                //s.push(nums2[j]);
            }
            else if(!s.empty() and nums2[j]>s.top())
            {
                while(!s.empty() && nums2[j]>s.top())
                {
                    s.pop();
                }
                if(s.empty()==true)
                {
                    ans.push_back(-1);
                    
                }
                else {
                    ans.push_back(s.top());
                    
                }
            }
            s.push(nums2[j]);
        }
        reverse(ans.begin(),ans.end());
        for(auto it : ans)cout << it << " ";
        int j = 0;
        for(int i = 0 ; i < ans.size();i++)
        {
            mapp[nums2[j++]] = ans[i];
        }
        vector<int>finalA;
        for(int i = 0 ; i < n ; i++)
        {
            finalA.push_back(mapp[nums1[i]]);
        }
        return finalA;
        
        
        
        
        
        
        
        
        
        
        
        
        // vector<int>ans(nums1.size(),0);
        // for(int i = 0 ; i < n ; i++)
        // {
        //     for(int j = 0 ; j < m ; j++)
        //     {
        //         if(nums2[j]==nums1[i])
        //         {
        //             j++;
        //             while(j<m && nums2[j]<nums1[i])
        //             {
        //                 j++;
        //             }
        //             if(j>=m)ans[i]=-1;
        //             else ans[i]=(nums2[j]);
        //         }
        //     }
        // }
        // return ans;
        
    }
};