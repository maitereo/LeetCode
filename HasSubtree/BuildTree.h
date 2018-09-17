#include <iostream>
#include <vector>
#ifndef TREESTRUCT
#define TREESTRUCT
#include "TreeStruct.h"
#endif

void LDR_traversal(TreeNode *tree);

void DLR_traversal(TreeNode *tree);

std::vector<int> output_LDR_traversal(std::vector<int> &vec, TreeNode *tree);

void output_DLR_traversal(std::vector<int> &vec, TreeNode *tree);

void print_vector(std::vector<int> input);

class BuildTree {
public:
	TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin);
};
