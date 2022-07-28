class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int i = 0 ; i < stones.size() ; i++)
        {
            q.push(stones[i]);
        }
        while(q.size()!=1)
        {
            int f = q.top();
            q.pop();
            int s = 0;
            if(!q.empty())
            {
                s = q.top();
                q.pop();
            }
            q.push(abs(f-s));
            
            
        }
        return q.top();
        
    }
};