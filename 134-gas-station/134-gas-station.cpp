static int speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i, j;
        for (i = 0; i < n; i += j){
            int sum = 0;
            for (j = 1; j <= n; j++){
                int k = (i + j - 1) % n;
                sum += (gas[k] - cost[k]);
                if (sum < 0)
                    break;
            }
            if (j > n)
                return i;
        }
        return -1;
    }
};