#include <iostream>
#include <stdlib.h>

//-------- solution with recursion ------------
// class Solution {
// public:
//     int Fibonacci(int n) {
//     	if(n == 2) return 1;
//     	else if (n == 1) return 0;
//     	return Fibonacci(n-1) + Fibonacci(n-2);
//     }
// };

class Solution {
public:
    int Fibonacci(int n) {

    	if(n == 0) return 0;
    	else if(n == 1) return 1;

    	int i, sum, component1 = 0, component2 = 1;
    	for(i=1; i<n; i++)
    	{
    		sum = component1 + component2;
    		component1 = component2;
    		component2 = sum;
    	}

    	return sum;
    }
};

int main(int argc, char *argv[])
{
	int input = atoi(argv[1]);
	Solution solution;
	int result = solution.Fibonacci(input);
	std::cout << result << std::endl;

	return 0;
}