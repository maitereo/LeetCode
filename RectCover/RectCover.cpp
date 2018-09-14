#include <iostream>
#include <stdlib.h>

class Solution 
{
    public:
        int rectCover(int number) 
        {
            if(number == 0) return 0;
            else if(number == 1) return 1;
            else if(number == 2) return 2;
            return rectCover(number-1) + rectCover(number-2);
        }
};

int main(int argc, char* argv[])
{
	int input = atoi(argv[1]);
	Solution solution;

	std::cout << solution.rectCover(input) << std::endl;

	return 0;
}