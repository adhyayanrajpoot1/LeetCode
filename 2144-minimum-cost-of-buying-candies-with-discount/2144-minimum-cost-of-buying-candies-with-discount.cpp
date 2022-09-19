class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int c = 0;
        for(int i = 0 ; i < cost.size() ; )
        {
            int j = 0;
            while(j<2 && i+j<cost.size())
            {
                c+=cost[i+j];
                j++;
            }
            cout<<c <<" ";
            i = i+j+1;
        }
        return c;
    }
};