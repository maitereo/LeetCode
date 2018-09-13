#include <iostream>
#include <stdlib.h>

/*
This question can be break down to a question of two
sub-questions. Each of the sub-question can be also
breakdown to sub-question of itself until the input 
reaches 1 or 0. When input is smaller than 2, then 
return 1, otherwise do recursion.
*/
class Solution 
{
public:
    int jumpFloor(int number) 
    {
        if(number < 2) return 1;
        return jumpFloor(number-1) + jumpFloor(number-2);
    }
};

int main(int argc, char* argv[])
{
	int input = atoi(argv[1]);
	Solution solution;
	std::cout << solution.jumpFloor(input) << std::endl;
	return 0;
}