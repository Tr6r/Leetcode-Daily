/*
LC 383 - Ransom Note
Time: O(N + M), Space: O(1)

Logic:
1. Count the frequency of each character in 'magazine'.
2. Decrement the count for each character found in 'ransomNote'.
3. If any character count drops below one return false
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> let_table(26, 0);
        if (magazine.size() <= 0) return false;
        if (ransomNote.size() <= 0) return true;
        for(int i = 0;i<magazine.size();i++)
            let_table[(int)magazine[i] - 97] ++;
        for(int i = 0;i<ransomNote.size();i++)
            if (let_table[(int)ransomNote[i] - 97]-- == 0)return false;
        return true;
    }
};