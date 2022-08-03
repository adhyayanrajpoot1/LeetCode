class Node{
    public:
    int diff;
    int x;
    int y;
};
 
class Solution {
public:
   struct cmp
    {
        bool operator()(Node a , Node b)
        {
            return a.diff > b.diff;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Node,vector<Node>,cmp>pq;
        for(auto it : points)
        {
            int a = it[0];
            int b = it[1];
            int dist = a*a+b*b;
            Node smallAns;
            smallAns.diff = dist;
            smallAns.x = a;
            smallAns.y = b;
            pq.push(smallAns);
        }
        vector<vector<int>>ans;
        while(k--)
        {
            auto vlad = pq.top();
            vector<int>v;
            v.push_back(vlad.x);
            v.push_back(vlad.y);
            ans.push_back(v);
            pq.pop();
        }
        return ans;
        
    }
};