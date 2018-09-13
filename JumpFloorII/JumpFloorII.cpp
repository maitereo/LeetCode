#include <iostream>
#include <stdlib.h>
#include <math.h>

/*
This question can be break down to a question of two
sub-questions. Each of the sub-question can be also
breakdown to sub-question of itself until the input 
reaches 1 or 0. When input is smaller than 2, then 
return 1, otherwise do recursion.
*/
// class Solution 
// {
// public:
//     int jumpFloorII(int number) 
//     {
//         if(number == 1) return 1;
//         int sum = 0;
//         for(int i = 1; i < number; i++)
//         {
//         	sum += jumpFloorII(number-i);
//         }
//         return sum;
//     }
// };

// class Solution {
//     // 1 2 4 8 16 32
// public:
//     int jumpFloorII(int number) 
//     {
//         int sum, list[number + 1];
//         list[0] = 1; list[1] = 1;
//         for(int i = 2; i <= number; i++)
//         {
//         	sum = 0;
//             for(int j = 0; j < i; j++)
//             {
//                 sum += list[j];
//                 std::cout << "looping: " << sum << std::endl;
//             }
//             list[i] = sum;
//         }
//         return list[number];
//     }
// };

// class Solution {
//     // 1 2 4 8 16 32
// public:
//     int jumpFloorII(int number) 
//     {
//         return pow(2,number-1);
//     }
// };

class Solution {
    // 1 2 4 8 16 32
public:
    int jumpFloorII(int number) 
    {
        return 1<<(number-1);
    }
};

int main(int argc, char* argv[])
{
	int input = atoi(argv[1]);
	Solution solution;
	std::cout << solution.jumpFloorII(input) << std::endl;
	return 0;
}