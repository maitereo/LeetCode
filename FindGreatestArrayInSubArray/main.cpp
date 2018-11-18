#include <iostream>
#include "function.h"

int main()
{
    int a[] = {-6,-3,-2,-7,-15,-1,-2,-2};
    std::vector<int> array(a, a + sizeof(a)/sizeof(int));

    for(int i = 0; i < 8; i++)
    std::cout << *(a+i) << " " ;
    std::cout << std::endl;

    Solution solution;
    int res = solution.FindGreatestSumOfSubArray(array);

    std::cout << "res:\n" << res << std::endl;

    return 0;
}
