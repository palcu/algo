class Stack {
    queue<int> q1;
    
    void reverseQueue() {
        for (int i=0; i<q1.size() - 1; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }

public:
    void push(int x) {
        q1.push(x);
        reverseQueue();
    }
    
    void pop() {
        q1.pop();
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
