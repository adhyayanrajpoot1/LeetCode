class Solution {
public:
    bool check(string&str)
    {
        int ch[256]={0};
        for(auto it : str)
        {
            ch[it]++;
            if(ch[it]>1)return false;
        }
        return true;
    }
    int maxi = INT_MIN;
    void f(int ind , string temp , vector<string>&arr)
    {
        if(ind==arr.size()){
            maxi = max((int)temp.size(),maxi);
            return;
        }
        
        string s = temp+arr[ind];
        if(check(s))
        {
            f(ind+1,s,arr);
        }
        f(ind+1,temp,arr);
    }
    int maxLength(vector<string>& arr) {
        f(0,"",arr);
        return maxi;
    }
};