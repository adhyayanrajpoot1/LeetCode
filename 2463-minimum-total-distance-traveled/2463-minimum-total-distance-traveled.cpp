#define ll long long int
#define sz(a) (int)a.size()

class Solution {
    int n, m;
    ll dp[101][101][101];
    ll solve(vector<int>& robot, vector<vector<int>>& factory, int i, int j, int lim) {
		// if all factories are taken but some robots are still left then we return big value '1e10' else if all robots and factories are taken then we return 0
        if(j >= m) return ((i < n) ? 1e10 : 0);
		
		// if all robots are repaired then we return 0 
        if(i >= n) return 0;
        ll &ans = dp[i][j][lim];
        if(ans != -1) return ans;
		
        ans = 1e18; // max initial value
		
		// if some lim of current factory is remaining then we can take it and add the absolute distance between factory and robot
        if(lim > 0) ans = solve(robot, factory, i + 1, j, lim - 1) + abs(robot[i] - factory[j][0]);
		
		// else we have another option to leave that factory and take next factory if available;
        if(j + 1 < m) ans = min(ans, solve(robot, factory, i, j + 1, factory[j + 1][1]));
        return ans;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n = sz(robot);
        m = sz(factory);
        sort(robot.begin(), robot.end()); // we will sort the position of all robots
        sort(factory.begin(), factory.end()); // we will sort the position of all factories
        memset(dp, -1, sizeof dp);
		
        return solve(robot, factory, 0, 0, factory[0][1]);
    }
};