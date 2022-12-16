class MyQueue {
public:
    stack<int> b1, b2;
    MyQueue() {
    }
    
    void push(int x) {
        b1.push(x);
    }
    
    int pop() {
        while(!b1.empty()){
            b2.push(b1.top());
            b1.pop();
        }
        int ans = b2.top();
        b2.pop();
        while(!b2.empty()){
            b1.push(b2.top());
            b2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!b1.empty()){
            b2.push(b1.top());
            b1.pop();
        }
        int ans = b2.top();
        while(!b2.empty()){
            b1.push(b2.top());
            b2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return b1.empty();
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