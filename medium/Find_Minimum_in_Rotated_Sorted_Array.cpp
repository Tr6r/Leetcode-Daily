/*
LC 153 - Find Minimum in Rotated Sorted Array
Time: O(logN), Space: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = INT_MAX;
        int e = nums.size() -1 , s = 0;
        int pivot = s + (e -s) /2;
        if (nums.size () < 2) {
            return nums[0]; 
        }
        while(e > s){
            if (pivot !=0 && nums[pivot -1] < min) {
                min = nums[pivot -1];
            }
            if (nums[pivot] < min) {
                min = nums[pivot];
            }

            if (pivot!=nums.size() -1 && nums[pivot + 1] < min){

                min = nums[pivot + 1];
            }
            // s + (e - s)/2
            // Left
            if (nums[pivot] <  nums[e]) {
                e = pivot - 1;
            } 
            // Right
            else {
                s = pivot +1;
            }
            pivot = e + (s - e)/2;
        }
        return min;
    }
};