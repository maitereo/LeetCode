#include <iostream>
#include "BuildTree.h"
#include "PrintFromTopToBottom.h"

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

	Solution solution;

	std::vector<int> result = solution.PrintFromTopToBottom(tree);

	for(int i = 0; i < result.size(); i++)
		std::cout << result[i] << " ";

	std::cout << "\n";

	return 0;
}