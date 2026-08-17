class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sp = 0;
        int ep = nums.size() - 1;
        int pivot = nums.size()/2;
        int s = -1;
        int e = -1;
        // tìm start
        if (pivot == 0 && nums.size() < 2) {
            if (nums.size() > 0 && nums[pivot] == target) return {0,0};
            else return {-1,-1};
        }
        while (sp <= ep) {
            if (nums[pivot] > target){
                int temp = pivot - 1;
                pivot = sp + (ep - sp )/2;
                ep = temp;
            } else if (nums[pivot] < target)
            {
                int temp = pivot + 1;    
                pivot = sp + (ep - sp )/2;
                sp = temp;
            }
            else {
                if (nums[pivot - 1] != target) {
                    s = pivot;
                    break;
                }
                int temp = pivot - 1;
                pivot = sp + (ep - sp )/2;
                ep = temp;
            }

        }
        sp = 0;
        ep = nums.size() - 1;
        pivot = nums.size()/2;
        while (sp <= ep) {
            if (nums[pivot] > target){
                int temp = pivot - 1;
                pivot = sp + (ep - sp )/2;
                ep = temp;
            } else if (nums[pivot] < target)
            {
                int temp = pivot + 1;    
                pivot = sp + (ep - sp )/2;
                sp = temp;
            }
            else {
                if (nums[pivot + 1] != target) {
                    e = pivot;
                    break;
                }
                int temp = pivot + 1;
                pivot = sp + (ep - sp )/2;
                sp = temp;
            }

        }
        return {s,e};
    }
};v