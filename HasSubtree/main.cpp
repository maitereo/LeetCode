#include <iostream>
#include "HasSubtree.h"
#include "BuildTree.h"

int main()
{

	// Initialization
	int pre_array[] = { 1,2,4,7,3,5,6,8 }, vin_array[] = { 4,7,2,1,5,3,8,6 };
	std::vector<int> pre(pre_array, pre_array + sizeof(pre_array) / sizeof(int));
	std::vector<int> vin(vin_array, vin_array + sizeof(vin_array) / sizeof(int));

	BuildTree build;

	TreeNode *tree = build.reConstructBinaryTree(pre, vin);

	// Traversal the tree
	std::cout << "\nLDR output: ";
	LDR_traversal(tree);
	std::cout << std::endl;
	std::cout << "DLR output: ";
	DLR_traversal(tree);
	std::cout << std::endl;

	int pre_sub[] = { 3,5,6,8 }, vin_sub[] = { 5,3,8,6 };
	std::vector<int> preSubtree(pre_sub, pre_sub + sizeof(pre_sub) / sizeof(int));
	std::vector<int> vinSubTree(vin_sub, vin_sub + sizeof(vin_sub) / sizeof(int));

	TreeNode *subtree = build.reConstructBinaryTree(preSubtree, vinSubTree);

	// Traversal the tree
	std::cout << "\nLDR output: ";
	LDR_traversal(subtree);
	std::cout << std::endl;
	std::cout << "DLR output: ";
	DLR_traversal(subtree);
	std::cout << std::endl;
	// Initialization is finished

	Subtree solution;
	std::cout << "The result is " 
			<< solution.HasSubtree(tree, subtree) << std::endl;


	return 0;
}