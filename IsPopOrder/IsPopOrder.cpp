#include <iostream>
#include <vector>

class Solution 
{
public:
    bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) 
    {
        if(pushV.empty() || popV.empty()) return false;
        std::vector<int> stack;
        for(int i = 0, j = 0; i < pushV.size(); i++)
        {
            stack.push_back(pushV[i]);
           	std::cout << "push " << stack.back() << std::endl;
            while( j < pushV.size() && stack.back() == popV[j] )
            {
            	std::cout << "pop " << stack.back() << std::endl;
                stack.pop_back();
                j++;
            }
            
        }
        
        return stack.empty();
    }
};

int main()
{
	int pushI[] = { 1,2,3,4,5 }, popI[] = { 4,5,3,2,1 };
	std::vector<int> pushV( pushI, pushI + sizeof(pushI)/sizeof(int) ),
		popV( popI, popI + sizeof(popI)/sizeof(int) );

	std::cout << "[pushV]\t[popV]\n";
	for(int i = 0; i < pushV.size(); i++)
		std::cout << "  " << pushV[i] << "\t  " << popV[i] << "\n";

	Solution solution;
	std::cout << "result is " << solution.IsPopOrder(pushV, popV) << std::endl;


	return 0;
}