#include <iostream>
#include "BuildTree.h"
#include "FindPath.h"

int main()
{

	// Initialization
	int pre_array[] = { 1,2,4,7,3,5,6,8 }, vin_array[] = { 4,7,2,1,5,3,8,6 };
	std::vector<int> pre(pre_array, pre_array + sizeof(pre_array) / sizeof(int));
	std::vector<int> vin(vin_array, vin_array + sizeof(vin_array) / sizeof(int));

	std::cout << "Create Tree\n";
	BuildTree build;
	TreeNode *tree = build.reConstructBinaryTree(pre, vin);

	// Traversal the tree
	std::cout << "NLR output: ";
	NLR_traversal(tree);
	std::cout << std::endl;
	std::cout << "LNR output: ";
	LNR_traversal(tree);
	std::cout << std::endl;

	int target;
	std::cout << "Enter target number to search: ";
	std::cin >> target;

	PathFinder finder;
	std::vector<std::vector<int> > result = finder.FindPath(tree, target);

	for(int i = 0; i < result.size(); ++i)
	{
		std::cout << "[ ";
		for(int i = 0; i < result[0].size(); ++i)
			std::cout << result[0][i] << " ";
		std::cout << "]" << std::endl;
	}
	return 0;
}