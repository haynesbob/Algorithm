/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = maxDepth(root->left) + 1;
        int rightDepth = maxDepth(root->right) + 1;
        return max(leftDepth,rightDepth);
    }
};
