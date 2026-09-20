/*
LC 69 - Sqrt(x)
Time: O(N), Space: O(1)
*/

class Solution
{
public:
    int mySqrt(int x)
    {
        int ret = 0;
        for (long i = 1; i <= x; i++)
        {
            if (i * i > x)
            {
                break;
            }
            else
                ret = i;
        }
        return ret;
    }
};