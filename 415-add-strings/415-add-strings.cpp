class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        string res= "";
        int i = 0 ,j=0;
        int carry=0;
        
        while(n1>=0 || n2>=0 ||carry)
        {
            int sum=0;
            if(n1>=0){
                sum+=(num1[n1--]-'0');
            }
            if(n2>=0)
            {
                sum+=(num2[n2--]-'0');
            }
            sum+=carry;
            carry = sum/10;
            sum=sum%10;
            res = to_string(sum)+res;
        }
        
        return res;
    }
};


