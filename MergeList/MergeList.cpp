#include <iostream>
#include <stdlib.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {}
};

ListNode* createNode(int &length)
{
	int val;
	std::cout << "Enter element 1: ";
	std::cin >> val;
	ListNode *pHead = new ListNode(val), *tpHead = pHead;

	for(int i = 1; i < length; i++)
	{
		std::cout << "Enter element " << i+1 << ": ";
		std::cin >> val;
		tpHead->next = new ListNode(val);
		tpHead = tpHead->next;
	}

	return pHead;
}

void printNode(ListNode *ptr)
{
	while(ptr != NULL)
	{
		std::cout << "Node: " << ptr->val
				<< "\t address: " << ptr << std::endl;
		ptr = ptr->next;
	}
}



class Solution 
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
    	if(pHead1 == NULL) return pHead2;
    	else if(pHead2 == NULL) return pHead1;
    	
    	std::cout << "Start merging\n";
    	ListNode *mergeHead = NULL, *current = NULL;

    	while( (pHead1 != NULL) && (pHead2 != NULL) )
    	{
	    	if( (pHead1 != NULL) && (pHead2 != NULL) )
	    	{
	    		// std::cout << "(pHead1 != NULL) && (pHead2 != NULL)\n"; 
	    		if(pHead1->val <= pHead2->val)
	    		{
	    			// std::cout << "(pHead1->val <= pHead2->val)\n"; 
	    			if(mergeHead == NULL) mergeHead = current = pHead1;
	    			else
	    			{
		    			current->next = pHead1;
		    			current = current->next;
	    			}
	    			pHead1 = pHead1->next;
	    		}
	    		else
	    		{
	    			// std::cout << "(pHead1->val > pHead2->val)\n"; 
	    			if(mergeHead == NULL) mergeHead = current = pHead2;
	    			else
	    			{
		    			current->next = pHead2;
		    			current = current->next;
	    			}
	    			pHead2 = pHead2->next;
	    		}
	    	}
    	}

    	if(pHead1 == NULL) current->next = pHead2;
    	if(pHead2 == NULL) current->next = pHead1;
    	return mergeHead;
    }
};

int main()
{
	int length1, length2;
	std::cout << "Enter lengths of List 1 and List 2: ";
	std::cin >> length1 >> length2;

	ListNode *pHead1 = createNode(length1);
	std::cout << "\nCreating linked list 1\n";
	printNode(pHead1);

	ListNode *pHead2 = createNode(length2);
	std::cout << "\nCreating linked list 2\n";
	printNode(pHead2);

	Solution solution;
	std::cout << "\nNew list\n";
	printNode(solution.Merge(pHead1,pHead2));


	return 0;
}