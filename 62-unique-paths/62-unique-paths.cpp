class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        int R = m-1;
        long res=1;
        for(int i = 1 ; i <=R ; i++)
        {
            res=res*(N-R+i)/i;
        }
        return res;
    }
};