/*
LC 268 - Missing Number
Time : O(N) - traverse every item in vector once
Space : O(N) - Create a vector to track missing number

Logic:
1. Traverse every item in the vector once
2. Mark the position in the created vector using the given vector value
3. Traverse every item in the created vector
4  If the item == 0, return that position as the missing number
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::vector<int> v(nums.size()+1,0);
        for(int i=0;i < nums.size();i++)
        {
            v[nums[i]] = 1;
        }
        for (int i = 0;i<v.size();i++)
        {
            if(v[i] == 0) return i;
        }
        return 0;
    }
};