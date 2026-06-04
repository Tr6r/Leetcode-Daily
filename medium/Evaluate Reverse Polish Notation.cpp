/*
LC 150 - Evaluate Reverse Polish Notation
Time : O(N) - 1 time traverse every string in vector
Space : O(N) - create a stack

logic:
1. Traverse every string in the vector once
2. If the current string is a number, convert and push it into the stack
3. If the current string is an operator:
    3.1 Pop the top two numbers from the stack
    3.2 Calculate the result based on the operator
    3.3 Push the result back into the stack
4. Return the top item in the stack
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                if (s == "+") stack.push(b + a);
                else if (s == "-") stack.push(b - a);
                else if (s == "*") stack.push(b * a);
                else stack.push(b / a);
            } else {
                stack.push(stoi(s));
            }
        }
        return stack.top();
    }
};