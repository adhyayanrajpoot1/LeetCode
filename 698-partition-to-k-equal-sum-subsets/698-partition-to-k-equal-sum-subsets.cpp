class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int K) {
        int N = nums.size();
        if (K == 1) return true;
        if (N < K) return false;
        int sum = 0;
        for (int i = 0; i < N; i++) sum += nums[i];
        if (sum % K != 0) return false;

        int subset = sum / K;
        int subsetSum[K];
        bool taken[N];

        for (int i = 0; i < K; i++) subsetSum[i] = 0;
        for (int i = 0; i < N; i++) taken[i] = false;

        subsetSum[0] = nums[N - 1];
        taken[N - 1] = true;

        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
    }

    bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
        if (subsetSum[curIdx] == subset) {
            if (curIdx == K - 2) return true;
            return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
        }

        for (int i = limitIdx; i >= 0; i--) {
            if (taken[i]) continue;
            int tmp = subsetSum[curIdx] + nums[i];

            if (tmp <= subset) {
                taken[i] = true;
                subsetSum[curIdx] += nums[i];
                bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
                if (nxt) return true;
            }
        }
        return false;
    }
    //set<vector<int>>s;
//     bool f(int ind ,int tar ,int sum ,int BN,vector<int>&temp, int k , vector<int>&num)
//     {
//         if(BN==k)return true;
        
//         if(tar<sum)return false;
//         if(tar==sum)
//         {
//             return f(0,tar,0,BN+1,temp,k,num);
//         }
//         if(ind>=num.size())return false;
//         if(temp[ind] ==1)
//         {
//             return f(ind+1,tar,sum,BN,temp,k,num);
//         }
//         else
//         {
//             sum+=num[ind];
//             temp[ind] = 1;
//             bool op1 = f(ind+1,tar,sum,BN,temp,k,num);
//             sum-=num[ind];
//             temp[ind] = 0;
            
//             bool op2 = f(ind+1,tar,sum,BN,temp,k,num);
            
//             return op1|op2;
            
//         }
        
        
        
//     }
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum = 0;
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             sum+=nums[i];
//         }
//         if(sum%k!=0)return false;
//         vector<int>temp(nums.size(),0);
//         return f(0,sum/k ,0,0,temp, k , nums);
//     }
};