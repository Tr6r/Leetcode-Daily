/*
LC 232 - Implement Queue using Stacks
Time: O(N), Space: O(N)
idea: Use stacks to implement queue behavior
*/

class MyQueue {
public:
    MyQueue() {}

    void push(int x) {
        if (s.size() == 0) {
            s.push(x);
            return;
        }
        int n = s.size();
        std::stack<int> s_temp;
        for (int i = 0; i < n; i++) {
            s_temp.push(s.top());
            s.pop();
        }
        s.push(x);
        for (int i = 0; i < n; i++) {
            s.push(s_temp.top());
            s_temp.pop();
        } 
    }

    int pop() {
        int temp = s.top();
        s.pop();
        return temp;
    }

    int peek() { return s.top(); }

    bool empty() { return s.empty(); }

private:
    std::stack<int> s;
};