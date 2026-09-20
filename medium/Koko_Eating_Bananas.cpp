/*
LC 875 - Koko Eating Bananas
Solution: Binary search
Time: O(N * log M), Space: O(1)
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() < 2) {
            return (piles[0] / h) + ((piles[0] % h) != 0 ? 1 : 0);
        }
        int min = 0, max = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] >= max) {
                max = piles[i];
            }
        }
        int pivot = min + (max - min) / 2;
        int result = INT_MAX;
        while (min <= max) {
            // logic kiểm tra
            int hour = h;
            bool ret = true;
            for (int i = 0; i < piles.size(); i++) {
                hour -= (piles[i] / pivot) + ((piles[i] % pivot) != 0 ? 1 : 0);
            }
            if (hour < 0) {
                ret = false;
            }
            if (!ret) {
                min = pivot + 1;
            } else {
                max = pivot - 1;
                if (result >= pivot) {
                    result = pivot;
                }
            }
            pivot = min + (max - min) / 2;
            if (pivot == 0) break;
        }
        return result;
    }
};