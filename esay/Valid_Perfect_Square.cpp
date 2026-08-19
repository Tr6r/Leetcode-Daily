/*
LC 367 - Valid Perfect Square
Time: O(N), Space: O(1)
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        for (long i =0; i <= num / 2; i++)
        {
            if (i*i > num) break; 
            else if (i*i == num) return true;
        }
        return false;
    }
};