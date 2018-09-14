#include <iostream>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
    	if(pListHead == NULL || k == 0)
    	{
    		std::cout << "List is empty or tring to find 0th value" << std::endl;
    		return NULL;
    	}
    	unsigned int counter = 0;
    	ListNode *ptr = pListHead;
    	while(ptr != NULL)
    	{
    		counter++;
    		ptr = ptr->next;
    	}

    	
    	if(counter < k) return NULL;

    	ptr = pListHead;
    	for(int i = 0; i < counter-k; i++) ptr = ptr->next;
    	return ptr;

    }
};

int main(int ac, char* av[])
{
	if(ac < 3)
	{
		std::cout << "Please input node number and target" << std::endl;
		return 0;
	}
	int nodeNumber = atoi(av[1]), target = atoi(av[2]);
	std::cout << "Creating linked list...\n";
	ListNode *Head = new ListNode(0), *ptr = Head;
	std::cout << "Head Created: " << Head->val << std::endl;
	for(int i = 1; i < nodeNumber; i++)
	{
		ptr->next = new ListNode(i);
		std::cout << "Node Created: " << ptr->next->val << std::endl;
		ptr = ptr->next;
	}

	Solution solution;
	ptr = Head;
	ListNode* result = solution.FindKthToTail(ptr, target);
	if(result==NULL) std::cout << "No target found" << std::endl;
	else std::cout << "Target is " << target << ", find result " << result->val << std::endl;

	return 0;
}
