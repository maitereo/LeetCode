#include <iostream>
#include <vector>
#ifndef TREESTRUCT
#define TREESTRUCT
#include "TreeStruct.h"
#endif

class Subtree 
{
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
};

bool matchTree2inTree1(TreeNode* pRoot1, TreeNode* pRoot2);
