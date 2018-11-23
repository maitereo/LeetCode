#include <iostream>
#include <stdlib.h>
#include "function.h"

int main(int argc, char* argv[])
{
    int input = atoi(argv[1]);
    Solution solution;
    int res = solution.GetUglyNumber_Solution(input);

    std::cout << input << "th ugly number is: " << res << "\n";

    return 0;
}