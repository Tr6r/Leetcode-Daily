/*
LC 34 - Find First and Last Position of Element in Sorted Array
Time: O(logN), Space: O(1)
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sp = 0;
        int ep = nums.size() - 1;
        int s = -1;
        int e = -1;
        // tìm start
        if (nums.size() < 2) {
            if (nums.size() == 1 && nums[0] == target) return {0,0};
            else return {-1,-1};
        }
        while (sp <= ep) {
                int pivot = sp + (ep - sp )/2;
            if (nums[pivot] > target){
                ep = pivot - 1;
            } else if (nums[pivot] < target)
            {
                sp = pivot + 1;
            }
            else {
                if (pivot == 0  ||nums[pivot - 1] != target) {
                    s = pivot;
                    cout<<"ok\n"<<endl;
                    break;
                }
                ep = pivot - 1;
            }
        }
        sp = 0;
        ep = nums.size() - 1;
        while (sp <= ep) {
               int pivot = sp + (ep - sp )/2;
            if (nums[pivot] > target){
                ep = pivot - 1;
            } else if (nums[pivot] < target)
            {
                sp = pivot + 1;
            }
            else {
                if (pivot == nums.size() -1  || nums[pivot + 1] != target) {
                    e = pivot;
                    break;
                }
                sp = pivot + 1;
            }

        }
        return {s,e};
    }
};