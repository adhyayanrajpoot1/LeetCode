class Solution {
public:
    int countCollisions(string directions) {
        stack<char>s;
        int ans = 0;
        for(auto &it : directions)
        {
            if(s.empty()){
                s.push(it);
                continue;
            }
            if(!s.empty() && s.top()=='R' && it=='L')
            {
                s.pop();
                s.push('S');
                ans+=2;
            }
            else if(!s.empty() && s.top()=='S' && it=='L')
            {
                //s.pop();
                //s.push('S');
                ans+=1;
            }
            else if(!s.empty() && s.top()=='R'&&it=='S')
            {
                ans+=1;
                s.pop();
                s.push('S');
                
            }
            else s.push(it);
        }
        while(!s.empty() && s.top()=='R')s.pop();
        while(!s.empty())
        {
            if(s.top()=='R')ans+=1;
            s.pop();
        }
        return ans;
    }
};


