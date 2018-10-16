#include <iostream>
#include <vector>
#ifndef TREESTRUCT
#define TREESTRUCT
#include "TreeStruct.h"
#endif

void NLR_traversal(TreeNode *tree);

void LNR_traversal(TreeNode *tree);

std::vector<int> output_NLR_traversal(std::vector<int> &vec, TreeNode *tree);

std::vector<int> output_LNR_traversal(std::vector<int> &vec, TreeNode *tree);

void print_vector(std::vector<int> input);

class BuildTree {
public:
	TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin);
};
