class MyStack {
    queue<int>Q1,Q2;
public:
        MyStack(){
            
        }
    
    void push(int x) {
        Q2.push(x);
        while(!Q1.empty()){
            Q2.push(Q1.front());
            Q1.pop();    
        }
        swap(Q1,Q2);
    }
    
    int pop() {
        int x=Q1.front();
        Q1.pop();
        return x;
    }
    
    int top() {
        return Q1.front();
    }
    
    bool empty() {
        return Q1.empty();
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