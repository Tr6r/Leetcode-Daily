/*
LC 735 - Asteroid Collision
Time : O(N^2) - While{for}
Space : O(N) - Create 1 vector

Logic:
1. Traverse items in the given vector
2. Store positive numbers
3. If the item is negative
4. Pop an item from the created vector
If the item is positive -> find the max -> push the max into the created vector
If the item is negative -> continue
5. If the size does not change after the while loop -> break the loop
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        bool flag = true;
        int size = asteroids.size();
        while (flag) {
            for (int i = 0; i < asteroids.size(); i++) {
                if (asteroids[i] > 0)
                    v.push_back(asteroids[i]);
                else if (asteroids[i] < 0 && i != 0 && asteroids[i-1] > 0) {
                    int temp = v.back();
                    if (temp < (-1 * asteroids[i])) {
                        v.pop_back();
                        v.push_back(asteroids[i]);
                    } else if (temp == (-1 * asteroids[i])) {
                        v.pop_back();
                    }
                }
                else if (asteroids[i] < 0 ||(asteroids[i-1] < 0 && i == 0))
                    v.push_back(asteroids[i]);
            }
            int size_temp = v.size();
            if (v.empty())
                flag = false;
            if (size_temp == size) {
                flag = false;
            } else {
                size = size_temp;
                asteroids = v;
                v.clear();
                for (int i = 0; i < asteroids.size(); i++) {
                    cout << asteroids[i] << endl;
                }
            }
        }
        return v;
    }
};