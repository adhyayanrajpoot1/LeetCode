class Solution {
public:
    bool check(vector<int> &selected, string &currString)
{
    vector<int> selfCheck(26, 0); 
    for (int i = 0; i < currString.size(); i++)
    {
        if (selfCheck[currString[i] - 'a'] == 1)
            return false ;
        selfCheck[currString[i] - 'a'] = 1 ;
    }
    for (int i = 0; i < currString.size(); i++)
    {
        if (selected[currString[i] - 'a'] == 1)
            return false ;
    }
    
    return true ;
}

    int help(int i , vector<string>&arr , vector<int>&perfect, int res)
    {
        if(i==arr.size())return res;
        string str = arr[i];
        if(check(perfect,str)==false)
        {
            return help(i+1,arr,perfect,res);
        }
        else
        {
            for(int i = 0 ; i < str.size() ; i++)
            {
                perfect[str[i]-'a']=1;
            }
            res+=str.size();
            int pick = help(i+1,arr,perfect,res);
            
            for(int i = 0 ; i < str.size() ; i++)
            {
                perfect[str[i]-'a']=0;
            }
            res-=str.size();
            int nonPick = help(i+1,arr,perfect,res);
            return max(pick,nonPick);
            
        }
        //return -1;
    }
    int maxLength(vector<string>& arr) {
        vector<int>perfect(26,0);
        return help(0,arr,perfect,0);
        
    }
};