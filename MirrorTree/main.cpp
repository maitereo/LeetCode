#include <iostream>
#include "BuildTree.h"
#include "Mirror.h"

int main()
{

	// Initialization
	int pre_array[] = { 8,10,11,9,6,7,5 }, vin_array[] = { 11,10,9,8,7,6,5 };
	std::vector<int> pre(pre_array, pre_array + sizeof(pre_array) / sizeof(int));
	std::vector<int> vin(vin_array, vin_array + sizeof(vin_array) / sizeof(int));

	std::cout << "Create Tree\n";
	BuildTree build;
	TreeNode *tree = build.reConstructBinaryTree(pre, vin);

	// Traversal the tree
	std::cout << "LDR output: ";
	LDR_traversal(tree);
	std::cout << std::endl;
	std::cout << "DLR output: ";
	DLR_traversal(tree);
	std::cout << std::endl;

	std::cout << "\nMirroring Tree\n";
	MirrorTree mirror;
	mirror.Mirror(tree);
	// Traversal the tree
	std::cout << "LDR output: ";
	LDR_traversal(tree);
	std::cout << std::endl;
	std::cout << "DLR output: ";
	DLR_traversal(tree);
	std::cout << std::endl;

	return 0;
}