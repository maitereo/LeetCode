#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "function.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    clock_t t = clock();
    int length = atoi(argv[1]);
    std::vector<int> input_vec(length);
    std::cout << "rand array:\n";
    for(std::vector<int>::iterator iter = input_vec.begin(); iter!=input_vec.end(); iter++)
    {
        *iter = rand() % 2 + 1;
        std::cout << *iter << "  ";
    }
    std::cout << "\n";
    
    Solution solution;
    int res = solution.MoreThanHalfNum_Solution(input_vec);
    t = clock() - t;
    std::cout << "result is: "<< res << "\ncomputing time: "
    << t << "clocks\n";

    return 0;
}