/*
LC 225 - Implement Stack using Queues
Time: O(N), Space: O(1)
idea: Use a single queue to implement stack behavior
*/
class MyStack {
public:
    MyStack() {
    }
    void push(int x) {
        queue.push(x);
        for (int i =0;i<queue.size()-1;i++)
        {
            int temp = queue.front();
            queue.pop();
            queue.push(temp);
        }
    }
    int pop() {
        int val = queue.front();
        queue.pop();
        return val;
    }
    int top() {
        return queue.front();
    }
    
    bool empty() {
        return queue.empty();
    }
private:
    std::queue<int> queue;
};
