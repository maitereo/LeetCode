/* Idea: 
1. Count depth from leafs to the root. For every node, check 
difference of depths of left subnode and right subnode. 
Return false if difference is larger than 1, otherwise 
return ture and count depth +1.

2. If reaches NULL while going downwards, return ture.
*/

#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot){
        int depth = 0;
        return check_depth(pRoot, depth);
    }
    
    bool check_depth(TreeNode* root, int &depth){
        if(!root) return true;
        int left = 0, right = 0;
        
        if(check_depth(root->left, left) && check_depth(root->right, right)){
            int diff = abs(left-right);
            if(diff > 1) return false;
            else{
                depth = (left > right ? left : right) + 1;
                return true;
            }
        }
        return false;
        
    }
};