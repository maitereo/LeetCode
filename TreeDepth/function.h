/* Idea: Traversal
Go to the deepest node of the tree, count depth while
going downwards. At the moment that reaches the leaf node,
remain the largest depth.
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
    int TreeDepth(TreeNode* pRoot)
    {
        count_depth(pRoot, 0);
        return depth_max;
    }
private:
    int depth_max = 0;
    void count_depth(TreeNode* pRoot, int depth)
    {
        if(!pRoot)
        {
            depth_max = (depth_max > depth) ? depth_max : depth;
            return;
        }
        count_depth(pRoot->left, depth+1);
        count_depth(pRoot->right, depth+1);
    }
};