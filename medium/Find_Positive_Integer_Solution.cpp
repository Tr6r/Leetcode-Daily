/*
LC 1237 - Find Positive Integer Solution for a Given Equation
Solution: Binary search
Time: O(N*logM), Space: O(1)
*/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int min = 1, max = 1000;
        int x = 1;
        int pivot = min + (max - min) / 2;
        vector<vector<int>> rc;
        bool flag = false;
        while (x <= z) {
            while (min <= max) {
                int result = customfunction.f(x, pivot) - z;
                if (result > 0) {
                    max = pivot -1;
                } else if (result < 0) {
                    min = pivot +1;

                } else {
                    flag = true;
                    break;
                }
                pivot = min + (max - min) / 2;   
            }
            if (flag) {
                vector<int> ret = {x, pivot};
                rc.push_back(ret);
                flag = false;
            }
            x++;
            min = 1;
            max = 1000;
        }
    return rc;
    }
};