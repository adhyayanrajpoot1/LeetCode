class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.length()-1;
        int m = b.length()-1;
        int carry = 0;
        string str="";
        while(n>=0 || m>=0 || carry)
        {
            if(n>=0)
            {
                carry+=(a[n]-'0');
                n--;
            }
            if(m>=0)
            {
                carry+=(b[m]-'0');
                m--;
            }
            str+=(carry%2+'0');
            carry/=2;
            
        }
        reverse(str.begin(),str.end());
        return str;
    }
};