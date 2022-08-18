class Solution {
public:
    //dp
    int nthUglyNumber(int n) {
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        vector<int>ans(n);
        ans[0] =1;
        for(int i = 1 ; i < n ; i++)
        {
            int m2 = 2*ans[p1];
            int m3 = 3*ans[p2];
            int m5 = 5*ans[p3];
            ans[i] = min(m2 , min(m3,m5));
            if(ans[i]==m2)p1++;
            if(ans[i]==m3)p2++;
            if(ans[i]==m5)p3++;
        }
        return ans[n-1];
    }
};