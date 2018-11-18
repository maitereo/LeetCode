#include <iostream>
#include "function.h"

/* Idea: Dynamic Programming
1. Return 0 if array is empty.

2. Initialize <sum> and <tempsum> to be the first element of 
the array.

3. Look at the element from the 2nd, if the element is greater
than 0, means the value of sum is going up, otherwise don't do
sum. Therefore, let <tempsum> be the element if element less than
0, otherwise sum <tempsum> and <element>.

4. If <tempsum> is greater than <sum>, replace <tempsum> to <sum>,
otherwise keep <sum> remains the same value.
*/

int Solution::FindGreatestSumOfSubArray(std::vector<int> array) {
    if(array.empty()) return 0;
    int sum = array[0], tempsum = array[0]; //注意初始值 不能设为0 防止只有负数
    for(int i = 1; i < array.size(); i++) //从1开始 因为0的情况在初始化时完成了
    {
        tempsum = (tempsum < 0) ? array[i] : tempsum + array[i];
        std::cout << "tempsum = " << tempsum << std::endl;
        sum = (tempsum > sum) ? tempsum : sum;
        std::cout << "sum = " << sum << std::endl;
    }
    return sum;
}