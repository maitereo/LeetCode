#include <iostream>
#include <stdlib.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {}
};


//       p0->p1->p2->p3->NULL
// NULL  p0  p1->p2->p3->NULL
// NULL<-p0  p1->p2->p3->NULL
// NULL<-p0  p1  p2->p3->NULL
// NULL<-p0<-p1  p2->p3->NULL
class Solution 
{
public:
    ListNode* ReverseList(ListNode* pHead) 
    {
    	if(pHead == NULL) return NULL;
    	ListNode *_pHead = NULL, *pHead_ = pHead->next;

    	while(pHead_ != NULL)
    	{
    		// std::cout << "\n_pHead :" << _pHead << std::endl
    		// 		<< " pHead :" << pHead << std::endl
    		// 		<< "pHead_ :" << pHead_ << std::endl;
    		pHead->next = _pHead;
    		_pHead = pHead;
    		pHead  = pHead_;
    		pHead_ = pHead_->next;
    	}
    	pHead->next = _pHead;

    	return pHead;

    }
};

void createNode(ListNode* ptr, int &nodeNumber)
{
	for(int i = 1; i < nodeNumber; i++)
	{
		ptr->next = new ListNode(i);
		ptr = ptr->next;
	}
}

void printNode(ListNode* ptr)
{
	while(ptr != NULL)
	{
		std::cout << "Node: " << ptr->val
				<< "\t address: " << ptr << std::endl;
		ptr = ptr->next;
	}
}

// This function takes input of <Number of Nodes, Target to Find>
// e.g. $ ./Solution 50 10
// Create 50 nodes with ascending order and reverse the list.
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

	createNode(ptr, nodeNumber);
	printNode(ptr);



	Solution solution;
	ListNode* result = solution.ReverseList(Head);
	std::cout << "\nNode Reversed\n";
	printNode(result);

	return 0;
}