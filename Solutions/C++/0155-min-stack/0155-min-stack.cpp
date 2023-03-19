class MinStack {
public:
    stack<vector<int>> s1;
    MinStack() {
        s1 = stack<vector<int>>();
    }
    
    void push(int val) {
        int mn = (s1.size()? min(val,s1.top()[1]): val);
        s1.push({val, mn});
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top()[0];
    }
    
    int getMin() {
        return s1.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */