/*
LC 70 - Climbing Stairs
Solution: Dynamic Programming
Time: O(N), Space: O(N)
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> pd (n  +1,0);
        pd[0] = 1;
        for(int i = 0;i< n;i ++) {
            pd[i + 1] += pd[i];

            if (i + 2 <= n) {
                pd[i + 2] += pd[i];
            }  
        }
        return pd[n];
    }
};