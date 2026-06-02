/*
LC 217 - Contains Duplicate

Time: O(N)  Traverse every item in the vector once.
Space : O(N) - Create unordered_map marking exits value.

Logic: Use an unordered_map to track a value has already appeared.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        for (int i =0; i<nums.size();i++)
        {
            hash_map[nums[i]]++;
            if(hash_map[nums[i]] >= 2) return true;
        }
        return false;

    }
};