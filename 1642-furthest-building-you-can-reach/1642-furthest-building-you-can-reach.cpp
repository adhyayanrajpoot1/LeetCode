class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int i;
        for(i = 0; i < heights.size()-1 ; i++)
        {
            int d = heights[i+1]-heights[i];
            if(d>0){
                pq.push(d);
                bricks-=d;
                if(bricks<0){
                    if(ladders<=0)return i;
                    bricks+=pq.top();
                    pq.pop();
                    ladders--;
                    
                }
                
                
            }
        }
        return i;
    }
};