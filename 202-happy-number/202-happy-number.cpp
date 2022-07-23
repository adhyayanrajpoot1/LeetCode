class Solution {
public:
    set<int>s;
    bool isHappy(int n) {
        // if(n>1e9)return false;
        if(n==1)return true;
        if(n<=0)return false;
        int sum = 0;
        int rem=0;
        s.insert(n);
        while(n>0)
        {
            rem=n%10;
            sum+=(pow(rem,2));
            n=n/10;
        }
        if(s.find(sum)!=s.end())return false;
        
        return isHappy(sum);
    }
};