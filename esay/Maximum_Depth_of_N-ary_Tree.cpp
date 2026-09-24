/*
LC 559 - Maximum Depth of N-ary Tree
Solution: Recursion
Time: O(N), Space: O(M)
*/

class Solution {
public:
    int max=0;
    int count =1;
    int maxDepth(Node* root) {
        if (!root) return 0;
        if (root->children.size() == 0) {
            if (max < count) max = count;

            return max;
        }
        for (int i = 0;i < root->children.size(); i++) {
            count ++;
            maxDepth(root->children[i]);
            count--;
        }
        return max;
    }
};