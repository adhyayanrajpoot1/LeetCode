class Solution {
public:
//     vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
//         int m = n;
//         vector<vector<int>>grid(n,vector<int>(m,0));
//         for(auto it : lamps)
//         {
//             int a = it[0];
//             int b = it[1];
            
//             for(int i = 0 ; i < m ; i++)
//             {
//                 if(i==b)continue;
//                 grid[a][i]++;
//             }
//             for(int j = 0 ; j < n ; j++)
//             {
//                 if(j==a)continue;
//                 grid[j][b]++;
//             }
//             int c = a , d = b;
//             while(a>=0 && b>=0)
//             {
//                 if(a==c && d==b)
//                 {
//                     a--;
//                     b--;
//                     continue;
//                 }
//                 grid[a--][b--]++;
               
//             }
//             a=c;
//             b=d;
//             while(a<n && b<m)
//             {
//                 if(a==c && d==b){
//                     a++;
//                     b++;
//                     continue;
//                 }
//                 grid[a][b]++;
//                 a++;
//                 b++;
//             }
//             a=c;
//             b=d;
//             while(a>=0 && b<m)
//             {
//                 if(a==c && d==b){
//                     a--;
//                     b++;
//                     continue;
//                 }
//                 grid[a][b]++;
//                 a--;
//                 b++;
//             }
//             a=c;
//             b=d;
//             while(a<n && b>=0)
//             {
//                 if(a==c && d==b){
//                     a++;
//                     b--;
//                     continue;
//                 }
//                 grid[a][b]++;
//                 a++;
//                 b--;
//             }
//             grid[c][d]++;
//         }
//         int i = 0;
//         vector<int>v(queries.size());
//         for(auto it : queries)
//         {
//             int a = it[0];
//             int b = it[1];
//             if(grid[a][b]>0){
//                 v[i]=1;
//                 if(a+1<n) grid[a+1][b] >0 ? grid[a+1][b]-- : 0;
//                 if(b+1<m)grid[a][b+1] >0 ? grid[a][b+1]-- : 0;
//                 if(a-1>=0)grid[a-1][b] >0 ? grid[a-1][b]-- : 0;
//                 if(b-1>=0)grid[a][b-1] >0 ? grid[a][b-1]-- : 0;
//                 if(a+1<n && b+1<m)grid[a+1][b+1] >0 ? grid[a+1][b+1]-- : 0;
//                 if(a-1>=0 && b-1>=0)grid[a-1][b-1] >0 ? grid[a-1][b-1]-- : 0;
//                 if(a+1<n && b-1>=0)grid[a+1][b-1] >0 ? grid[a+1][b-1]-- : 0;
//                 if(a-1>=0 && b+1<m)grid[a-1][b+1] >0 ? grid[a-1][b+1]-- : 0;  
//             } 
//             else v[i] = 0;
//             i++;
//         }
//         return v;
//     }
    
    //An insert operation on a set returns a pair, with its member first set to an iterator pointing to either the newly inserted element or to the equivalent element already in the set. The second element in the pair is set to true if a new element was inserted or false if an equivalent element already existed.
    
    
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
      vector<int> res;
      unordered_map<int, int> x, y, a_d, d_d;
      unordered_map<int, unordered_set<int>> ls;
      for (auto l : lamps) {
        auto i = l[0], j = l[1];
          //cout <<  << " ";
        if (ls[i].insert(j).second) ++x[i], ++y[j], ++a_d[i + j], ++d_d[i - j];
      }
      for (auto q : queries) {
        auto i = q[0], j = q[1];
        if (x[i] || y[j] || a_d[i + j] || d_d[i - j]) {
          res.push_back(1);
          for (auto li = i - 1; li <= i + 1; ++li)
            for (auto lj = j - 1; lj <= j + 1; ++lj){
              if (ls[li].erase(lj)) {
                --x[li], --y[lj], --a_d[li + lj], --d_d[li - lj];
              }
          }
        }
        else res.push_back(0);
      }
      return res;
    }
};