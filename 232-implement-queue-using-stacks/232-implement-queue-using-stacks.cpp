class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ele = -1;
        while(!s1.empty())
        {
            ele = s1.top();
            s1.pop();
            s2.push(ele);
        }if(!s2.empty())s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ele;
    }
    
    int peek() {
        int ele = -1;
        while(!s1.empty())
        {
            ele = s1.top();
            s1.pop();
            s2.push(ele);
        }
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ele;
    }
    
    bool empty() {
        return s1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */