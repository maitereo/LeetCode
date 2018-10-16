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

#include "FindPath.h"

void PathFinder::find(TreeNode* root, int target)
{
    if(!root) return;
    path.push_back(root->val);
    if(!root->left && !root->right && target == root->val) // If is leaf-node, root->left == NULL, root->right == NULL
        res.push_back(path);
    else
    {
        if(root->left) find(root->left, target - root->val);
        if(root->right) find(root->right, target - root->val);
    }
    path.pop_back();
}

std::vector<std::vector<int> > PathFinder::FindPath(TreeNode* root, int expectNumber)
{
    find(root, expectNumber);
    return res;
}