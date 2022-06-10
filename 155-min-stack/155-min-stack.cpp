class MinStack {
public:
    stack<int>first;
    stack<int>second;
    MinStack() {
        
    }
    
    void push(int val) {
        first.push(val);
        if(second.size()==0)
        {
            second.push(val);
        }
        else
        {
            second.push(min(second.top(),val));
        }
    }
    
    void pop() {
        first.pop();
        second.pop();
    }
    
    int top() {
        return first.top();
    }
    
    int getMin() {
        return second.top();
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