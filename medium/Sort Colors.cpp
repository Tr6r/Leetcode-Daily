/*
LC 75 - Sort Colors.
Time : O(N) - traverse every items in array once.
Space : O(1)

Logic:
1. Just apply couting sort algorihm
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp(3,0);
        int count = 0;
        if (nums.size() <= 1) return;
        for(int i = 0;i<nums.size();i++)
        {
            int index = nums[i]; 
            temp[index] ++;
        }
        for(int i = 0;i<3;i++)
        {
            for(int j= 0;j<temp[i];j++)
            {
                nums[count] = i;
                count++;
            }
        }   
    }
};