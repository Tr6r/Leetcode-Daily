/*
LC 977 - Squares of a Sorted Array
Time : O(N) - Traverse every item in the vector once.
Space : O(N) - Create new vector storing a result.

Logic:
1. Create 2 pointers pointing to the beginning and the end of the vector.
2. Traverse every item in the vector.
3. If the squared item at index i is bigger than the squared item at index j -> store the item in a new vector and increase i.
4. If the squared item at index i is smaller than the squared item at index j -> store the item in a new vector and decrease j.
5. When i > j -> stop.
6. Reverse the vector.
*/
class Solution {
public: 
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> new_nums;
        int i  =0 ,j = nums.size() -1 ;
        if (nums.size() < 1) return nums;
        while(i<=j)
        {
            if (pow(nums[i], 2) >= pow(nums[j], 2))
            {
                new_nums.push_back(pow(nums[i], 2));
                i++;
            }
            else if (pow(nums[i], 2) < pow(nums[j], 2))
            {
                new_nums.push_back(pow(nums[j], 2));
                j--;
            }
        }
        reverse(new_nums.begin(),new_nums.end());
        return new_nums;
    }
};