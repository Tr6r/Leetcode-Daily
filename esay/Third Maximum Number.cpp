/*
LC 414 - Third Maximum Number
Time : O(N) - Traverse every item in the vector once.
Space : O(1)

Logic:
1. Declare 3 long-type variables.
2. Traverse every item in the vector.
3. If the item is bigger than max1 -> swap the position of each max.
4. If the item is bigger than max2 -> swap the positions of max2 and max3.
5. If the item is bigger than max3 -> update max3.
6. If max3 == LONG_MIN -> return max1; otherwise return max3.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
    long max1= LONG_MIN;
    long max2= LONG_MIN;
    long max3= LONG_MIN;
    for (int i=0;i<nums.size();i++)
    {
        if (max1 == nums[i] ||max2 == nums[i] || max3 == nums[i])
            continue;
        if (max1<nums[i])
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if (max2<nums[i])
        {
            max3 = max2;
            max2 = nums[i];
        }
        else if (max3<=nums[i])
        {
            cout<<i<<endl;
            cout<<nums[i]<<endl;
            max3 = nums[i];
        }
    }
    if (max3 != LONG_MIN) return max3;
    return max1;
    }
};