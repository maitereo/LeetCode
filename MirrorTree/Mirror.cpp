#include "Mirror.h"


/* Idea: recursion
1. If  is NULL, return.

2. If left and right roots are both NOT NULL, go to subroots.

3. Swap left and right roots

*/
void MirrorTree::Mirror(TreeNode *pRoot) 
{
	if(!pRoot) return;

	std::cout << "Root: " << pRoot->val << std::endl;

	if( (pRoot->left != NULL) || (pRoot->right != NULL) )
	{
		Mirror(pRoot->left);
		Mirror(pRoot->right);

		std::cout << "Swapping " << pRoot->left->val
			<< " and " << pRoot->right->val << std::endl;
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
	}
}