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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (root == NULL)
            return v;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int length = q.size();
            vector<int>
                vec; // must be initialize here else it can't be reseted and
                     // contained previous values as a result give error
            for (int i = 0; i < length; i++) {
                TreeNode* current = q.front();
                q.pop();
                vec.push_back(current->val);
                if (current->left != NULL)
                    q.push(current->left);
                if (current->right != NULL)
                    q.push(current->right);
            }
            v.push_back(vec);
        }
        return v;
    }
};