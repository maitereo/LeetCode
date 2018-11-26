/* Idea: Traversal
Assume <list1> has length a+x, and <list2> has
length b+x. If a>b, then the first (a-b)'s elements
of <list1> can be ignored. Therefore, only compare
b+x parts of <list1> and <list2> is necessary.

1. Return NULL if any of input pointer is NULL

2. Count length of both lists;

3. Line up <p1> and <p2> to make lengths after the 
pointers are equal.

4. If <p1->val> == <p2->val>, check whether list after
<p1> and <p2> are same. If yes, return <p1>, Otherwise 
move <pi> and <p2> to next. 

5. If all nodes are checked and no match during the 
process, return NULL.
*/

#include <stdlib.h>
#include <algorithm>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        if(!pHead1 || !pHead2) return NULL;
        ListNode *p1 = pHead1, *p2 = pHead2;
        int length1 = 0, length2 = 0;
        while(p1) 
        {
            length1++;
            p1 = p1->next;
        }
        while(p2) 
        {
            length2++;
            p2 = p2->next;
        }
        
        int length_min = std::min(length1,length2);
        int offset1 = length1 - length_min, offset2 = length2 - length_min;
        p1 = pHead1; p2 = pHead2;
        for(int i = 0; i < offset1; ++i) p1 = p1->next;
        for(int i = 0; i < offset2; ++i) p2 = p2->next;
        
        while(p1)
        {
            if(p1->val == p2->val)
                if(traceBack(p1,p2)) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
        
    }
    
    bool traceBack(ListNode* p1, ListNode* p2)
    {
        if(!p1) return true;
        bool res;
        if(p1->val != p2->val) 
        {
            res = false;
            return false;
        }
        else res = true;
        return res || traceBack(p1->next, p2->next);
    }
};