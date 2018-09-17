#include "HasSubtree.h"

/* Idea: Recursion
1. First check if input argument is invalid.

2. Inside recursion
	a. 

*/

bool matchTree2inTree1(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(!pRoot2) return true;	// check if tree2 is fitted inside tree1
	if(!pRoot1) return false;	// not match if tree1 reaches leaf.

	if(pRoot1->val != pRoot2->val) return false;

	return (matchTree2inTree1(pRoot1->left, pRoot2->left) &&
			matchTree2inTree1(pRoot1->right, pRoot2->right));
}

bool Subtree::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(!pRoot1 || !pRoot2) return false; // Question defined

	return matchTree2inTree1(pRoot1, pRoot2) ||
		HasSubtree(pRoot1->left, pRoot2) ||
		HasSubtree(pRoot1->right, pRoot2);
}



