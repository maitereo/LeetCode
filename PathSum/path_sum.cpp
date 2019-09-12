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
    bool calcSum(TreeNode* root, int sum) {
        if (!root) {
            if (sum == 0) return true;
            else return false;
        }
        if (!root->left && !root->right && root->val == sum) return true; 
        if (!root->left) return calcSum(root->right, sum - root->val);
        if (!root->right) return calcSum(root->left, sum - root->val);
        return calcSum(root->left, sum - root->val) || calcSum(root->right, sum - root->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return calcSum(root, sum);
    }
};