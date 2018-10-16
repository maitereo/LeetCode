#include "BuildTree.h"

void NLR_traversal(TreeNode *tree)
{
	if (tree != NULL)
	{
		std::cout << tree->val << "  ";
		NLR_traversal(tree->left);
		NLR_traversal(tree->right);
	}
}

void LNR_traversal(TreeNode *tree)
{
	if (tree != NULL)
	{
		LNR_traversal(tree->left);
		std::cout << tree->val << "  ";
		LNR_traversal(tree->right);
	}
}

std::vector<int> output_NLR_traversal(std::vector<int> &vec, TreeNode *tree)
{
	if (tree != NULL)
	{
		std::cout << "pushing " << tree->val << std::endl;
		vec.push_back(tree->val);
		output_NLR_traversal(vec, tree->left);
		output_NLR_traversal(vec, tree->right);
	}
	return vec;
}

std::vector<int> output_LNR_traversal(std::vector<int> &vec, TreeNode *tree)
{
	if (tree != NULL)
	{
		output_LNR_traversal(vec, tree->left);
		std::cout << "pushing " << tree->val << std::endl;
		vec.push_back(tree->val);
		output_LNR_traversal(vec, tree->right);
	}

	return vec;
}

void print_vector(std::vector<int> input)
{
	// std::cout << "size of vector is: " << input.size() << std::endl;
	for (int i = 0; i < input.size(); i++)
	{
		std::cout << input[i] << "  ";
	}
	std::cout << std::endl;
	return;
}

TreeNode* BuildTree::reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
	if (pre.empty() || vin.empty()) return NULL;

	// The first root must be the pre[0], and find where is the root
	// node in vin.
	int divide_index = 0, i;
	for (; divide_index < vin.size(); divide_index++)
	{
		if (pre[0] == vin[divide_index]) break;
	}
	// std::cout << "\nthe divide_index is " << divide_index << std::endl;

	TreeNode *root = new TreeNode(pre[0]);
	// std::cout << "current node is: " << pre[0] << std::endl;

	// Divide the vector into left and right of the tree.
	// The number of node on the left equals to the number of vin_left.
	// DLR goes everything on the left, so the number of node on the left of 
	// LDR's devide_index shows how many nodes will go to the left of the tree 
	// after current node of DLR.
	std::vector<int> pre_left, pre_right, vin_left, vin_right;
	for (i = 0; i < divide_index; i++)
	{
		pre_left.push_back(pre[i + 1]);
		vin_left.push_back(vin[i]);
	}
	for (i = divide_index+1; i < vin.size(); i++)
	{
		pre_right.push_back(pre[i]);
		vin_right.push_back(vin[i]);
	}

	// // std::cout << "pre_left: ";
	// print_vector(pre_left);

	// // std::cout << "pre_right: ";
	// print_vector(pre_right);

	// // std::cout << "vin_left: ";
	// print_vector(vin_left);

	// // std::cout << "vin_right: ";
	// print_vector(vin_right);
	// Do recursion to get next root.
	// std::cout << "going left\n";
	root->left = reConstructBinaryTree(pre_left, vin_left);
	// std::cout << "going right\n";
	root->right = reConstructBinaryTree(pre_right, vin_right);
	
	return root;
}