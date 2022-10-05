class MinStack {
public:
    stack<int> st;
    stack<int> mnSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mnSt.size()){
            mnSt.push(min(mnSt.top(), val));
        } else {
            mnSt.push(val);
        }
    }
    
    void pop() {
        st.pop();
        mnSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnSt.top();
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