/*
LC 561 - Array Partition
Time : O(N logN) - use sort function
Space : O(1)

Logic:
1. Sort the given vector
2. Find the min in the continuous pair and sum all the min
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for (int i=0;i<nums.size();i+=2)
        {
            sum+=min(nums[i],nums[i+1]);
        }
        return sum;
    }
};