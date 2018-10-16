#include <iostream>
#include <vector>
#ifndef TREESTRUCT
#define TREESTRUCT
#include "TreeStruct.h"
#endif
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// Yizhou Shan
/* Idea: DFS(Deep First Search) with recursion.
1. Terminate at the beginning if the <Tree> has no <node>.

2. Put <node> into <path>

3. Check if the current <node> is leaf-node && the value matches.
If yes, put <path> into <result>, otherwise continue.

4. Go to <sub-nodes> and substract <node_val> from <target>.

5. If the <target> does not match at the <leaf-node>, pop the last
element from <path> until it reaches the <node> which has another
way to go.
*/

class PathFinder {
	std::vector<std::vector<int> >  res;
	std::vector<int> path;

	void find(TreeNode* root, int target);

public:
    std::vector<std::vector<int> > FindPath(TreeNode* root,int expectNumber);
};