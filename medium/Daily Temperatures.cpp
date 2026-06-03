/*
LC 739 - Daily Temperatures
Time : O(N) - 1 time traverse every items in vector
Space : O(N) - create a vector using as stack

logic:
1. Create a pre variable as the first one in the vector
2. Traverse every item except the first one in the vector once
3. If the item is bigger than pre:
    3.1 Set the item to 1 and compare it with all items in the stack
    3.2 If the item is bigger than the item in the stack, overwrite the data in the vector
4. If the item is smaller, push the previous index into the stack
5. Update pre to the current item
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> stack;
        int pre = temperatures[0];
        for (int i = 1; i < temperatures.size(); i++) {
            if (pre < temperatures[i]) {
                temperatures[i - 1] = 1;
                for (int j = 0; j < stack.size(); j++) {
                    int temp = stack[j];
                    if (temperatures[temp] < temperatures[i]) {
                        temperatures[temp] = i - temp;
                        stack.erase(stack.begin() + j);
                        j--;
                    }
                }
            } else {
                stack.push_back(i - 1);
            }
            pre = temperatures[i];
        }
        cout << stack.size() << endl;
        for (int j = 0; j < stack.size(); j++) {            
            temperatures[stack[j]] = 0;
        }
        temperatures[temperatures.size() - 1] = 0;
        return temperatures;
    }
};