/*
LC 169 - Majority Element
Time: O(N), Space: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = nums[0];
        int count  = 1;

        for (int i = 1 ; i<nums.size(); i++) {
            if ( nums[i]== m) {
                count ++;
            } else {
                count --;
                if (count < 0) {
                    m = nums[i];
                    count = 1;
                }
            }
        }
        return m;
    }
};