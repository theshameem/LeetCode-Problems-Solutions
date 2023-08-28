class MyStack {
public:
    deque<int> Q;
    MyStack() {
        
    }
    
    void push(int x) {
        Q.push_front(x);
    }
    
    int pop() {
        int val = Q.front();
        Q.pop_front();
        return val;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */