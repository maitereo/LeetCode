#include <iostream>
#include <vector>
#include <queue>
#ifndef TREESTRUCT
#define TREESTRUCT
#include "TreeStruct.h"
#endif

/* Idea: Push the tree nodes into a queue in order

1. If the tree is empty, return an empty vector

2. Push the root node into queue at the begining.

3. Push the node value of in the front of the queue.

4. If there is left or right subnodes, push subroots
into queue with order from left to right.

5. Because the node value is already pushed into vector,
pop it out from queue. The next element will become the
element.

6. Repeat instructions 2 to 5 if there is anything left
int the queue.

7. Return the result.

*/

class Solution 
{
public:
    std::vector<int> PrintFromTopToBottom(TreeNode* root) 
    {
        std::vector<int> result;
        if(!root) return result; // Return empty vector if the tree is empty

        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            result.push_back(q.front()->val);

            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);

            q.pop();
        }
        
        return result;
    }
};