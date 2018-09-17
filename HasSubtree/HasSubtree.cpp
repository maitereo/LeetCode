#include "HasSubtree.h"

/* Idea: Recursion
1. First check if input argument is invalid.

2. Inside recursion of matchTree2inTree1()
	a. If current nodes are matched, keep checking subnodes;
	b. If current nodes are NOT matched, return false;
	c. Tree2 is a subtree of tree1 if tree2 reaches leaf first.
	d. Tree2 is NOT a subtree of tree1 if tree1 reaches leaf first.

3. If the current node is NOT equal, go to root nodes (left and right)
and do the process.

4. Tree2 is a subtree of tree1 if matchTree2inTree1 at anytime.

*/

bool matchTree2inTree1(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(!pRoot2) return true;	// check if tree2 is fitted inside tree1
	if(!pRoot1) return false;	// not match if tree1 reaches leaf.

	if(pRoot1->val != pRoot2->val) return false; // not a subtree if NOT equal

	return (matchTree2inTree1(pRoot1->left, pRoot2->left) &&
			matchTree2inTree1(pRoot1->right, pRoot2->right)); // go to root nodes.
}

bool Subtree::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(!pRoot1 || !pRoot2) return false; // Question defined

	return matchTree2inTree1(pRoot1, pRoot2) ||
		HasSubtree(pRoot1->left, pRoot2) ||
		HasSubtree(pRoot1->right, pRoot2);

	// equivalent to
	// bool result = matchTree2inTree1(pRoot1, pRoot2);
	// if(!result) result = HasSubtree(pRoot1->left, pRoot2);
	// if(!result) result = HasSubtree(pRoot1->right, pRoot2);
	// return result;
}



