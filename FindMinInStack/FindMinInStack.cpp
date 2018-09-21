#include <iostream>
#include <stack>

class Solution 
{
public:
    void push(int value)
    {
        s.push(value);
        if(s_min.empty()) s_min.push(value);
        else
        {
        	if(value <= s_min.top()) s_min.push(value);
        }
    }
    void pop() 
    {
       	if(s.empty()) return;
       	if(s.top() == s_min.top())
       	{
       		s.pop();
       		s_min.pop();
       	}
       	else s.pop();
    }
    int top() 
    {
        return s.top();
    }
    int min() 
    {
        return s_min.top();
    }
private:
	std::stack<int> s;
	std::stack<int> s_min;
};

int main()
{

	return 0;
}