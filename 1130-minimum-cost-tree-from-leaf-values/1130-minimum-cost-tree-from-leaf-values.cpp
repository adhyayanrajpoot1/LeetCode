class Solution {
public:
       int mctFromLeafValues(vector<int>& A) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
//     vector<vector<int>>v;
//     int f(vector<int>arr ,map<pair<int,int>,int>m , int s , int e)
//     {
//         if(s==e)return 0;
        
//         if(v[s][e]!=-1)return v[s][e];
//         int ans= INT_MAX;
//         for(int i = s ; i < e ; i++)
//         {
//             ans = min(ans, m[{s,i}]*m[{i+1,e}]+f(arr,m,s,i)+f(arr,m,i+1,e));
//         }
//         return v[s][e]=ans;
//     }
//     int mctFromLeafValues(vector<int>& arr) {
//         map<pair<int,int>,int>m;
        
//         int n = arr.size();
//         v.resize(n+1,vector<int>(n+1,-1));
//         for(int i = 0 ; i < n ; i++)
//         {
//             m[{i,i}] = arr[i];
//             for(int j = i+1 ; j < n ; j++)
//             {
//                 m[{i,j}] = max(arr[j] , m[{i,j-1}]);
//             }
//         }
//         return f(arr,m , 0 , n-1);
//     }
};