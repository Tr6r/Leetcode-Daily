/*
LC 75 - Sort Colors.
Time : O(N) - traverse every items in array once.
Space : O(1)

Logic: Apply Dutch National Flag Algorithm (GPT recommended)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, mid = 0, right = nums.size() -1;
        if (nums.size() <= 1) return;
        while(mid<=right)
        {
            if (nums[mid] == 2)
            {
                swap(nums[mid], nums[right]);
                right --;
            }
            if (nums[mid] == 1) mid ++;
            else if(nums[mid] == 0)
            {
                swap(nums[mid], nums[left]);
                mid ++;
                left ++;
            }
        }
    }
};