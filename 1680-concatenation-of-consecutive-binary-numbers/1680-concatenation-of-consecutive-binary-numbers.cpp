class Solution {
public:
//     int mod = 1e9+7;
//     int concatenatedBinary(int n) {
//         string ans = "";
//         for(int i = 1 ; i <= n ; i++)
//         {
//             int num = i;
//             string str = "";
//             while(num>0)
//             {
//                 int rem = num%2;
//                 str+=to_string(rem);
//                 reverse(str.begin(),str.end());
//                 num=num/2;
                
//             }
//             cout<<str<<" ";
//             ans+=str;
//         }
//         cout<<endl;
//         long long a = 0;
//         cout<<ans<<' ';
//         for(int i = ans.size()-1,j=0 ; i>=0 ; i--,j++)
//         {
//             long long p = pow(2,j);
//             p=p%mod;
//             if(ans[i]=='1')a=(a+p)%mod;
//         }
//         return a%mod;
//     }
   
    int concatenatedBinary(int n) {
        long long int val = 0;
        int i=1;
        while(i<=n)
        {
            val = ((val << (1+int(log2(i))))%1000000007 + i)%1000000007;
            i+=1;
        }
        return val;
    }

};