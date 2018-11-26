#include <iostream>
#include "function.h"

int main(int argc, char* argv[])
{
    std::string str = *(argv+1);
    
    Solution solution;
    std::cout << "The index of the first nonrepeated char is: " << solution.FirstNotRepeatingChar(str) << std::endl;

    return 0;
}