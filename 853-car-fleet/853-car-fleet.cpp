class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>s;
        vector<pair<int,int>>v(speed.size());
        for(int i = 0 ; i < speed.size() ; i++)
        {
            v[i].first = position[i];
            v[i].second = speed[i];
        }
        sort(v.begin(),v.end());
        for(int i = speed.size()-1 ; i>=0 ; i--)
        {
            double num = target-v[i].first;
            num = num/v[i].second;
            cout<<num<<" ";
            if(!s.empty() && s.top()>=num)
            {
                continue;
            }
            s.push(num);
        }
        return s.size();
    }
};