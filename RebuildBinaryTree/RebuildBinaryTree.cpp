#include <iostream>
#include <vector>

/*
***** Binary tree rebuild using BTT(Binary Tree Traversal) *****
Input results of DLR(Preorder traversal) & LDR(Inoder traversal), please rebuild the binary tree.
Assume results of DLR and LDR have no repeated element.
E.g. result of DLR{1,2,4,7,3,5,6,8} and LDR {4,7,2,1,5,3,8,6}, rebuild the binary tree.
*/

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void LDR_traversal(TreeNode *tree)
{
	if (tree != NULL)
	{
		std::cout << tree->val << ", ";
		LDR_traversal(tree->left);
		LDR_traversal(tree->right);
	}
}

void DLR_traversal(TreeNode *tree)
{
	if (tree != NULL)
	{
		DLR_traversal(tree->left);
		std::cout << tree->val << ", ";
		DLR_traversal(tree->right);
	}
}

std::vector<int> output_LDR_traversal(std::vector<int> &vec, TreeNode *tree)
{
	if (tree != NULL)
	{
		std::cout << "pushing " << tree->val << std::endl;
		vec.push_back(tree->val);
		output_LDR_traversal(vec, tree->left);
		output_LDR_traversal(vec, tree->right);
	}
	return vec;
}

void output_DLR_traversal(std::vector<int> &vec, TreeNode *tree)
{
	if (tree != NULL)
	{
		output_DLR_traversal(vec, tree->left);
		std::cout << "pushing " << tree->val << std::endl;
		vec.push_back(tree->val);
		output_DLR_traversal(vec, tree->right);
	}
}

void print_vector(std::vector<int> input)
{
	std::cout << "size of vector is: " << input.size() << std::endl;
	for (int i = 0; i < input.size(); i++)
	{
		std::cout << input[i] << ", ";
	}
	std::cout << std::endl;
	return;
}

class Solution {
public:
	TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
		if (pre.empty() || vin.empty()) return NULL;

		// The first root must be the pre[0], and find where is the root
		// node in vin.
		int divide_index = 0, i;
		for (; divide_index < vin.size(); divide_index++)
		{
			if (pre[0] == vin[divide_index]) break;
		}
		std::cout << "\nthe divide_index is " << divide_index << std::endl;

		TreeNode *root = new TreeNode(pre[0]);
		std::cout << "current node is: " << pre[0] << std::endl;

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

		std::cout << "pre_left: ";
		print_vector(pre_left);

		std::cout << "pre_right: ";
		print_vector(pre_right);

		std::cout << "vin_left: ";
		print_vector(vin_left);

		std::cout << "vin_right: ";
		print_vector(vin_right);
		// Do recursion to get next root.
		std::cout << "going left\n";
		root->left = reConstructBinaryTree(pre_left, vin_left);
		std::cout << "going right\n";
		root->right = reConstructBinaryTree(pre_right, vin_right);
		
		return root;
	}
};

//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(std::vector<int> prev, std::vector<int> vin)
//	{
//		if (prev.empty() || vin.empty())
//			return NULL;
//
//
//		size_t index = 0;
//		for (; index < vin.size(); index++)
//		{
//			if (vin[index] == prev[0])
//				break;
//		}
//
//
//		TreeNode* root = new TreeNode(prev[0]);
//
//		std::vector<int> prev_left, prev_right;
//		std::vector<int> vin_left, vin_right;
//
//		for (size_t j = 0; j < index; j++)
//		{
//			prev_left.push_back(prev[j + 1]);
//			vin_left.push_back(vin[j]);
//		}
//		for (size_t j = index + 1; j < vin.size(); j++)
//		{
//			prev_right.push_back(prev[j]);
//			vin_right.push_back(vin[j]);
//		}
//
//		root->left = reConstructBinaryTree(prev_left, vin_left);
//		root->right = reConstructBinaryTree(prev_right, vin_right);
//
//		return root;
//	}
//};


int main()
{
	int pre_array[] = { 1,2,4,7,3,5,6,8 }, vin_array[] = { 4,7,2,1,5,3,8,6 };
	std::vector<int> pre(pre_array, pre_array + sizeof(pre_array) / sizeof(int));
	std::vector<int> vin(vin_array, vin_array + sizeof(vin_array) / sizeof(int));

	print_vector(pre);
	print_vector(vin);

	Solution solve;

	TreeNode *tree = solve.reConstructBinaryTree(pre, vin);

	// Traversal the tree
	std::cout << "\nLDR output: ";
	LDR_traversal(tree);
	std::cout << std::endl;
	std::cout << "DLR output: ";
	DLR_traversal(tree);
	std::cout << std::endl;

	std::vector<int> pre2, vin2;
	std::cout << "\nOut put DLR traversals\n";
	output_DLR_traversal(pre2, tree);
	std::cout << "\nOut put DLR traversals\n";
	output_LDR_traversal(vin2, tree);

	std::cout << "\nLDR output: ";
	print_vector(pre2);
	std::cout << std::endl;
	std::cout << "DLR output: ";
	print_vector(vin2);
	std::cout << std::endl;



	system("pause");
	return 0;
}
