/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL || root2 == NULL)
            return root1 == root2;
        bool leftSame = isIdentical(root1->left, root2->left);
        bool rightSame = isIdentical(root1->right, root2->right);
        return leftSame && rightSame && root1->val == root2->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL)
            return root == subRoot;
        if (root->val == subRoot->val && isIdentical(root, subRoot))
            return true;
        bool isLeftSub = isSubtree(root->left, subRoot);
        bool isRightSub = isSubtree(root->right, subRoot);
        return isLeftSub || isRightSub;
    }
};