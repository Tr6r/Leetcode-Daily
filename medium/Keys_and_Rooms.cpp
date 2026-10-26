/*
LC 841 - Keys and Rooms
Hours Effort: 00:17:16
Solution: Stack
Time: O(N), Space: O(N)
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size_r = rooms.size();
        vector<int> md_r(size_r, 0);
        stack<int> st;
        for (int i = 0; i < rooms[0].size(); i++) {
            st.push(rooms[0][i]);
        }
        md_r[0] = 1;
        while (!st.empty()) {
            int key = st.top();
            st.pop();
            if (md_r[key] == 1)
                continue;
            for (int i = 0; rooms[key].size() > 0 && i < rooms[key].size();
                 i++) {
                st.push(rooms[key][i]);
            }
            md_r[key] = 1;
        }
        for (int i = 0; i < size_r; i++) {
            if (md_r[i] == 0)
                return false;
        }
        return true;
    }
};