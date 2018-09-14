#include <iostream>
#include <stdlib.h>

class Solution {
public:
    double Power(double base, int exponent) {
        double result = 1;
        if(exponent > 0) for(int i = 0; i < exponent; i++) result *= base;
        if(exponent < 0) for(int i = 0; i > exponent; i--) result /= base;
        return result;
    }
};

int main(int argc, char* argv[])
{
	int base = atoi(argv[1]), exponent = atoi(argv[2]);
	Solution solution;

	std::cout << "Result of " << base 
		<< " to the power of " << exponent 
		<< " is " << solution.Power(base, exponent) << std::endl;

	return 0;
}