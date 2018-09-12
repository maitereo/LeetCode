#include <iostream>
#include <stack>
#include <queue>

class Solution
{
public:
	void push(int node) {
		if (stack1.empty() && stack2.empty())
		{
			std::cout << "\nIn push, stack2 is empty\n"
				<< "Size of stack2 is " << stack2.size() << std::endl
				<< "Size of stack1 is " << stack1.size() << std::endl;
		}
		else
		{
			std::cout << "\nIn push, stack2 is not empty\n"
				<< "Size of stack2 is " << stack2.size() << std::endl
				<< "Size of stack1 is " << stack1.size() << std::endl;
			while (!stack2.empty())
			{
				stack1.push(stack2.top());
				std::cout << "putting " << stack1.top() << " into stack1\n";
				stack2.pop();
			}
		}

		stack1.push(node);
		std::cout << "pushed " << stack1.top() << std::endl;
	}

	int pop() {
		if (stack1.empty() && stack2.empty())
		{
			std::cout << "\nIn pop, stack1 is empty\n"
				<< "Size of stack2 is " << stack2.size() << std::endl
				<< "Size of stack1 is " << stack1.size() << std::endl;
			return NAN;
		}
		else
		{
			std::cout << "\nIn pop, stack1 is not empty\n"
				<< "Size of stack2 is " << stack2.size() << std::endl
				<< "Size of stack1 is " << stack1.size() << std::endl;

			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				std::cout << "putting " << stack2.top() << " into stack2\n";
				stack1.pop();
			}
			std::cout << "poping " << stack2.top() << std::endl;
			int return_value = stack2.top();
			stack2.pop();
			return return_value;
		}
	}

private:
	std::stack<int> stack1;
	std::stack<int> stack2;
};

int main()
{

	Solution queue;

//	for (int i = 0; i < 10; i++) queue.push(i);
//	for (int i = 0; i < 10; i++) queue.pop();
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.pop();
	queue.pop();
	queue.push(4);
	queue.pop();
	queue.push(5);
	queue.pop();
	queue.pop();


	system("pause");
	return 0;
}
