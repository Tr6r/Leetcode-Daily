/*
LC 1304 - Find N Unique Integers Sum up to Zero
Hours Effort: 00:07:48
Time: O(N), Space: O(N)
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret(n, 0);
        if (n % 2 == 0) {
            int st = (n / 2) * (-1);
            for (int i = 0; i < n; i++) {
                if (st == 0) {
                    st++;
                    i--;
                    continue;
                }
                ret[i] = st;
                st++;
            }
        } else {
            int st = (n / 2) * (-1);
            for (int i = 0; i < n; i++) {
                ret[i] = st;
                st++;
            }
        }
        return ret;
    }
};