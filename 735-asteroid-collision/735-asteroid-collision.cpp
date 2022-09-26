class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || s.empty()) {
                s.push(ast[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(ast[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(ast[i]);
                    }
                }
            }
        }
        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int l = 0 ;
//         int r = asteroids.size()-1;
//         while(asteroids[l]<0)l++;
//         while(asteroids[r]>0)r--;
//         stack<int>s;
//         s.push(asteroids[l]);
//         for(int i =l+1 ; i <= r ; i++)
//         {
//             while(!s.empty() && abs(asteroids[i])> s.top())
//             {
//                 if(asteroids[i]<0 && s.top()>0)
//                 {
//                     s.pop();
//                 }
//                 else if(asteroids[i]>0 && s.top()<0)s.pop();
//             }
//             if(!s.empty() && asteroids[i] < s.top())continue;
//             s.push(asteroids[i]);
//         }
//         vector<int>ans;
//         while(!s.empty())
//         {
//             ans.push_back(s.top());
//             s.pop();
//         }
//         reverse(ans.begin() , ans.end());
//         return ans;
//     }
// };