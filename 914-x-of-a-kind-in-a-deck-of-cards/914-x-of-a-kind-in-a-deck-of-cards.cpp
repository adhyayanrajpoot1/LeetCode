class Solution {
public:
    int gcd(int a , int b)
    {
        if(b==0)return a;
        return gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>m;
        for(int i = 0 ; i < deck.size() ; i++)
        {
            m[deck[i]]++;
        }
        int maxi = m[deck[0]];
        for(auto it : m)
        {
            maxi  = gcd(maxi , it.second);
            //if(m[it]<2)return false;
        }
        return maxi>=2;
    }
};