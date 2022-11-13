class Solution {
public:
    vector<string>ans;
    void f(int ind ,string&t ,  unordered_map<char,vector<char>>&m, string&digits)
    {
        if(t.size()>digits.size())return;
        if(t.size()==digits.size())
        {
            ans.push_back(t);
            return;
        }
        if(ind==digits.size())return;
        for(int i = 0 ; i < m[digits[ind]].size() ; i++)
        {
            t+=m[digits[ind]][i];
            f(ind+1,t,m,digits);
            t.pop_back();
        }
        f(ind+1,t,m,digits);
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        unordered_map<char,vector<char>>m;
        m['2'].push_back('a');
        m['2'].push_back('b');
        m['2'].push_back('c');
        m['3'].push_back('d');
        m['3'].push_back('e');
        m['3'].push_back('f');
        m['4'].push_back('g');
        m['4'].push_back('h');
        m['4'].push_back('i');
        m['5'].push_back('j');
        m['5'].push_back('k');
        m['5'].push_back('l');
        m['6'].push_back('m');
        m['6'].push_back('n');
        m['6'].push_back('o');
        m['7'].push_back('p');
        m['7'].push_back('q');
        m['7'].push_back('r');
        m['7'].push_back('s');
        m['8'].push_back('t');
        m['8'].push_back('u');
        m['8'].push_back('v');
        m['9'].push_back('w');
        m['9'].push_back('x');
        m['9'].push_back('y');
        m['9'].push_back('z');
        string temp = "";
        f(0,temp,m,digits);
        return ans;
    }
};