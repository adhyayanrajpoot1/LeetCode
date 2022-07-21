
static int speedup = [](){
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(0);
     return 0;
}();

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int startp = 0;
        int cap = 0;
        
        for(int i = 0; i < gas.size(); i++){
            cap += gas[i] - cost[i];
            if(cap < 0){
                cap = 0;
                startp = i + 1;
            }
            
            total += gas[i] - cost[i];
        }
        
        return total < 0 ? -1 : startp;
        }
};