/*
LC 704 - Binary Search
Time: O(logN), Space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot  = nums.size() / 2;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            if (nums[pivot] > target) {
                end = pivot - 1;
                pivot = (end - start) / 2;
            }
            else if (nums[pivot] < target) {
                start = pivot + 1;
                pivot = (end + start) / 2;
            }
            else return pivot;
        }
        return -1;      
    }
};