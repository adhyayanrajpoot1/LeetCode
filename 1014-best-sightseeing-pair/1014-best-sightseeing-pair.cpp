class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = INT_MIN;
        for(int i = 1 , j = values[0]-1; i < n ; i++)
        {
            maxi = max(maxi , j+values[i]);
            j = max(j , values[i])-1;
        }
        return maxi;
    }
};