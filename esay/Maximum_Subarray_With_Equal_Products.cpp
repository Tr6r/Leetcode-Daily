/*
LC 3411 - Maximum Subarray With Equal Products
Time: O(N^2), Space: O(1)
*/

class Solution {
public:
    void cal_pro_gcd_lcm(vector<int>& nums, int s, int e, int& p, int& g,
                         int& l) {
        g = 0;
        l = 1;
        p = 1;

        for (int i = s; i <= e; i++) {
            p = p * nums[i];
            g = gcd(g, nums[i]);
            l = lcm(l, nums[i]);
        }
    }
    int maxLength(vector<int>& nums) {
        int max = 2;
        int p2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            int count_fail = 0;
            for (int j = i; j < nums.size(); j++) {
                int p, g, l;
                cal_pro_gcd_lcm(nums, p2, j, p, g, l);
                if (p != g * l) {
                    count_fail++;
                    if (count_fail == 2)
                        break;
                } else if (max < j - p2 + 1)
                    max = j - p2 + 1;
            }
            p2++;
        }
        return max;
    }
};