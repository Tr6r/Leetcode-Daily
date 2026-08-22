/*
LC 1346 - Check If N and Its Double Exist
Time: O(N^2), Space: O(1)
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i =0;i<arr.size();i++) {
            for (int j = i + 1; j<arr.size();j++) {
                if (arr[j]*2 == arr[i] || arr[i]*2 == arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};