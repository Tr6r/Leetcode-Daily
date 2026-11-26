/*
LC 3360 - Stone Removal Game
Time: O(1), Space: O(1)
*/

class Solution {
public:
    bool canAliceWin(int n) {
        int time = 0;
        while (true) {
            n = n - (10 - time++);
            if (n < 0) return false;
            n = n - (10 - time++);
            if (n < 0) return true;
        };
    }
};