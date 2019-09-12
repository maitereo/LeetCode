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
    bool checkSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
        if(!leftNode && !rightNode) return true;
        
        if(leftNode && rightNode && leftNode->val == rightNode->val) {
            return checkSymmetric(leftNode->left, rightNode->right) && checkSymmetric(leftNode->right, rightNode->left);
        } else {
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return checkSymmetric(root->left, root->right);
    }
};