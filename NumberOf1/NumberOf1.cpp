#include <iostream>
#include <bitset>
#include <stdlib.h>

// class Solution
// {
//     public:
//         int  NumberOf1(int n)
//         {
//             int sum = 0, bit = 1;
//             uint un = n;
//             while(un!=0)
//             {
//                 sum += (int)un&bit;
//                 un >>= 1;
//                 std::cout << std::bitset<32>(un) << std::endl;
//             }
//             return sum;
//         }
// };


class Solution
{
    public:
        int  NumberOf1(int n)
        {
        	// Optimal function
        	// everytime n-1 will remove the right most
        	// bit with value '1', this function will
        	// only loop number of '1' times.
            int sum = 0;
            while(n!=0)
            {
                sum++;
                n = (n-1) & n;
            }
            return sum;
        }
};

int main(int argc, char* argv[])
{
	int input = atoi(argv[1]);
	Solution solution;
	std::cout << solution.NumberOf1(input) << std::endl;
	return 0;
}