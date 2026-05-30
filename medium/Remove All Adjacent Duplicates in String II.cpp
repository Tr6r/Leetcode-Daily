/*
LC 1209 - Remove All Adjacent Duplicates in String II.
Time : O(N) - 1 time traverse every char in string.
Space : O(N) - extra string + vector.

Logic:
1. Create a string (result), a vector (count frequency)
2. Traverse every char in string
3. If current char equals previous char -> increase frequency, else reset frequency to 1.
4. If frequency reaches k:
    - remove last k-1 chars from result
    - remove last k-1 frequencies
    - restore previous state from stack
5. Else push current char and frequency into stack.
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string new_n;
        std::vector<int> a;
        char pre_let = NULL;
        int count_let = 1;
        for (int i = 0; i < s.size(); i++) {
            if (pre_let == s[i])
                if (count_let >= k)
                count_let = 1;
                else 
                count_let++;
            else
                count_let = 1;
            if (count_let == k) {
                for (int n = 0; n < k - 1; n++) {
                    new_n.pop_back();
                    a.pop_back();
                }
                if (!a.empty()) {
                    count_let = a.back();
                    pre_let = new_n.back();
                }
            } else {
                new_n.push_back(s[i]);
                a.push_back(count_let);
                pre_let = s[i];
            }
        }
        return new_n;
    }
};