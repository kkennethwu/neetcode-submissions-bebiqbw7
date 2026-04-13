class MinStack {
public:
    stack<int> A, B;
    MinStack() {}
    
    void push(int val) {
        A.push(val);
        if (!B.empty()) {
            B.push(min(val, B.top()));
        }
        else B.push(val);
    }
    
    void pop() {
        A.pop();
        B.pop();
    }
    
    int top() {
        return A.top();
    }
    
    int getMin() {
        return B.top();
    }
};
