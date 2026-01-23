class MyQueue {
public:
    stack<int> my_st, temp_st;
    // [my_st][]
    void relax() {
        if (my_st.size()) return;
        while (temp_st.size()) {
            my_st.push(temp_st.top());
            temp_st.pop();
        }
    }

    MyQueue() {
    }
    
    void push(int x) {
        temp_st.push(x);
    }
    
    int pop() {
        relax();
        int x = my_st.top();
        my_st.pop();
        return x;
    }
    
    int peek() {
        relax();
        return my_st.top();
    }
    
    bool empty() {
        return !(my_st.size() + temp_st.size());
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