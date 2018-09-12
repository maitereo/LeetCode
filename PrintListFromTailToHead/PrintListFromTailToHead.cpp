#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//------------------------ Method 1 ------------------------------------
/*
using recursive, insert list to vector from the end to begining.
*/
//class Solution {
//public:
//	vector<int> printListFromTailToHead(struct ListNode* head) {
//		vector<int> value;
//		if (head != NULL)
//		{
//			value.insert(value.begin(), head->val);
//			if (head->next != NULL)
//			{
//				vector<int> tempVec = printListFromTailToHead(head->next);
//				if (tempVec.size() > 0)
//					value.insert(value.begin(), tempVec.begin(), tempVec.end());
//			}
//
//		}
//		return value;
//	}
//};

//------------------------ Method 2 ------------------------------------
/*
Violent solve the question, store list into vector followed by reverse.
*/
class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		ListNode *ptr = head;
		vector<int> return_value;

		if (head == NULL) return return_value;

		while (ptr->next != NULL)
		{
			return_value.push_back(ptr->val);
			ptr = ptr->next;
		}
		return_value.push_back(ptr->val);

		std:reverse(return_value.begin(), return_value.end());
		return return_value;
	}
};

int main()
{
	ListNode *ptr = new ListNode(0), *ptr_start = ptr;
	cout << "Construction started.\n" << ptr->val << ' ' << ptr_start << endl;

	for (int i = 1; i < 1; i++)
	{
		ptr->next = new ListNode(i);
		cout << ptr->next->val << ' ' << ptr->next << endl;
		ptr = ptr->next;
	}
	cout << "List constructed.\n\n";

	Solution solve;
	
	vector<int> reversed_list = solve.printListFromTailToHead(ptr_start);
	cout << "Print solution:\n";
	for (vector<int>::iterator iter = reversed_list.begin(); iter != reversed_list.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << "Print finished\n\n";

	system("pause");
	return 0;
}
