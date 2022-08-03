class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int end=0;
        int n=s.size();
        for(int i=1;i<n;i++)
        {
		
		    // for even length palindroms
            int l=i-1;           
            int h=i;
            while(l>=0 && h<n && s[l]==s[h])   //if both left and right is same then expand the length by of pallindrom by moving l and h accordingly
            {
                if(end-start < h-l )           // if current length of pallindrom is greater than previous the update start and end accordingly
                {
                    start=l;
                    end=h;
                }
                l--;
                h++;
            }
            
			//for odd length palindroms
            l=i-1;
            h=i+1;
            while(l>=0 && h<n && s[l]==s[h])
            {
                if(end-start < h-l )
                {
                    start=l;
                    end=h;
                }
                l--;
                h++;
            }
        }
        
        string ans="";
        for(int i=start;i<=end;i++)
            ans+=s[i];
        
        return ans;
    }
    
};
