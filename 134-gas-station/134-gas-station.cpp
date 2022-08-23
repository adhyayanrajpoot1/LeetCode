class Solution {
public:
    
    
     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(accumulate(gas.begin() , gas.end() , 0) < accumulate(cost.begin() , cost.end() , 0))return -1;
        int r = 0;
        int ans= 0;
        for(int i = 0 ; i < n ; i++)
        {
            r +=gas[i]-cost[i];
            if(r<0){
                ans = i+1;
                r = 0;
            }
        }
         return ans;
    }
    
    
    
//     bool check(vector<int>&gas , vector<int>&cost , int ind)
//     {
//         int fuel = gas[ind]-cost[ind];
//         for(int j = ind+1 ; j < gas.size() ; j++)
//         {
//             if(fuel<=0)return false;
//             fuel = fuel + gas[j] - cost[j];
//             cout << fuel << " ";
            
            
//         }
//         for(int j = 0 ; j < ind ; j++)
//         {
//             if(fuel<=0)return false;
//             fuel = fuel + gas[j] - cost[j];
//             cout << fuel << " ";
            
//         }
//         if(fuel<0)return false;
//         return true;
//     }
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
//         for(int i = 0 ; i < gas.size() ; i++)
//         {
//             if(cost[i] > gas[i])continue;
//             else{
//                 if(check(gas,cost,i))return i;
//             }
//         }
//         return -1;
//     }
};