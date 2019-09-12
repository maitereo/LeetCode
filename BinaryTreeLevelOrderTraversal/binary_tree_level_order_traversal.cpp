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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<vector<TreeNode*>> traversal;

        result.assign(1, vector<int>(1, root->val));
        traversal.assign(1, vector<TreeNode*>(1, root));
        
        // push current level's sub-elements into vector, and iterate until there is no sub-element.
        for(int i = 0; i < traversal.size() ; ++i) {
            vector<TreeNode*> cur_level;
            vector<int> cur_level_val;
            for(int j = 0; j < traversal[i].size(); ++j) {
                if(traversal[i][j]->left) {
                    cur_level.push_back(traversal[i][j]->left);
                    cur_level_val.push_back(traversal[i][j]->left->val);
                }
                if(traversal[i][j]->right) {
                    cur_level.push_back(traversal[i][j]->right);
                    cur_level_val.push_back(traversal[i][j]->right->val);
                }
            }
            if(!cur_level.empty()) {
                traversal.push_back(cur_level);
                result.push_back(cur_level_val);
            }
        }
        
        return result;
    }
};