class Queue {
private:
    stack<int> s1, s2;
    
    void move_stack_elements(stack<int>& from, stack<int>& to) {
        while (!from.empty()) {
            to.push(from.top());
            from.pop();
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        move_stack_elements(s1, s2);
        s1.push(x);
        move_stack_elements(s2, s1);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s1.pop();
    }

    // Get the front element.
    int peek(void) {
        return s1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
};
