class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string st = strs[0];
        //int mini = INT_MAX;
        string res="";
        for(int i = 1 ; i < n ; i++)
        {
            res="";
            int len1 = st.size();
            int len2 = strs[i].size();
            int k=0 ,j=0;
            //int count=0;
            while(k<len1 && j<len2){
                if(st[k]==strs[i][j++])
                {
                    res+=st[k];
                    k++;
                }
                else break;
                
                
            }
            st = res;
        }
        return st;
    }
};