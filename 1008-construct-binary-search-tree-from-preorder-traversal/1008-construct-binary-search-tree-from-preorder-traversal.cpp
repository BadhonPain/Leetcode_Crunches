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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            root = insert(root, preorder[i]);
        }
        return root;
    }

private:
    TreeNode* insert(TreeNode* root, int item) {
        if (root == NULL)
            return new TreeNode(item);

        if (root->val > item)
            root->left = insert(root->left, item);
        else
            root->right = insert(root->right, item);
        return root;
    }
};